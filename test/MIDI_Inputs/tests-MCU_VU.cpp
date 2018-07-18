#include <MIDI_Inputs/MCU_VU.hpp>
#include <gtest/gtest.h>

using namespace ::testing;

// -------------------------------------------------------------------------- //

TEST(MCUVU, setValue) {
    constexpr uint8_t channel = 3;
    constexpr uint8_t track = 5;
    MCU_VU vu(track, channel);
    MIDI_message_matcher midimsg = {CHANNEL_PRESSURE, channel - 1,
                                    (track - 1) << 4 | 0xA, 0};
    EXPECT_CALL(ArduinoMock::getInstance(), millis()).WillOnce(Return(0));
    MIDI_Input_ChannelPressure::updateAllWith(midimsg);
    EXPECT_EQ(vu.getValue(), 0xA);
}

TEST(MCUVU, setOverload) {
    constexpr uint8_t channel = 2;
    constexpr uint8_t track = 6;
    MCU_VU vu(track, channel);
    MIDI_message_matcher midimsg = {CHANNEL_PRESSURE, channel - 1,
                                    (track - 1) << 4 | 0xE, 0};
    MIDI_Input_ChannelPressure::updateAllWith(midimsg);
    EXPECT_EQ(vu.getValue(), 0);
    EXPECT_TRUE(vu.getOverload());
}

TEST(MCUVU, clearOverload) {
    constexpr uint8_t channel = 3;
    constexpr uint8_t track = 5;
    MCU_VU vu(track, channel);
    MIDI_message_matcher midimsgSet = {CHANNEL_PRESSURE, channel - 1,
                                       (track - 1) << 4 | 0xE, 0};
    MIDI_Input_ChannelPressure::updateAllWith(midimsgSet);
    MIDI_message_matcher midimsgClr = {CHANNEL_PRESSURE, channel - 1,
                                       (track - 1) << 4 | 0xF, 0};
    MIDI_Input_ChannelPressure::updateAllWith(midimsgClr);
    EXPECT_EQ(vu.getValue(), 0);
    EXPECT_FALSE(vu.getOverload());
}

TEST(MCUVU, retainValueAfterOverload) {
    constexpr uint8_t channel = 3;
    constexpr uint8_t track = 5;
    MCU_VU vu(track, channel);
    MIDI_message_matcher midimsg = {CHANNEL_PRESSURE, channel - 1,
                                    (track - 1) << 4 | 0x6, 0};
    EXPECT_CALL(ArduinoMock::getInstance(), millis()).WillOnce(Return(0));
    MIDI_Input_ChannelPressure::updateAllWith(midimsg);
    EXPECT_EQ(vu.getValue(), 0x6);
    MIDI_message_matcher midimsgSet = {CHANNEL_PRESSURE, channel - 1,
                                       (track - 1) << 4 | 0xE, 0};
    MIDI_Input_ChannelPressure::updateAllWith(midimsgSet);
    EXPECT_EQ(vu.getValue(), 0x6);
    MIDI_message_matcher midimsgClr = {CHANNEL_PRESSURE, channel - 1,
                                       (track - 1) << 4 | 0xF, 0};
    MIDI_Input_ChannelPressure::updateAllWith(midimsgClr);
    EXPECT_EQ(vu.getValue(), 0x6);
    EXPECT_FALSE(vu.getOverload());
}

TEST(MCUVU, decay) {
    constexpr uint8_t channel = 3;
    constexpr uint8_t track = 5;
    constexpr unsigned int decayTime = 300;
    MCU_VU vu(track, channel, decayTime);
    MIDI_message_matcher midimsg = {CHANNEL_PRESSURE, channel - 1,
                                    (track - 1) << 4 | 0xA, 0};
    EXPECT_CALL(ArduinoMock::getInstance(), millis()).WillOnce(Return(0));
    MIDI_Input_ChannelPressure::updateAllWith(midimsg);
    EXPECT_EQ(vu.getValue(), 0xA);
    EXPECT_CALL(ArduinoMock::getInstance(), millis())
        .WillOnce(Return(decayTime));
    MIDI_Input_ChannelPressure::updateAll();
    EXPECT_EQ(vu.getValue(), 0x9);
}

// -------------------------------------------------------------------------- //

TEST(MCUVUBankable, setValueBankChangeAddress) {
    constexpr uint8_t channel = 3;
    constexpr uint8_t track = 5;
    MCU_VU_Bankable<2> vu(track, channel);
    Bank bank(4);
    bank.add(vu, Bank::CHANGE_ADDRESS);
    MIDI_message_matcher midimsg = {CHANNEL_PRESSURE, channel - 1,
                                    (track + 4 - 1) << 4 | 0xA, 0};
    EXPECT_CALL(ArduinoMock::getInstance(), millis()).WillOnce(Return(0));
    MIDI_Input_ChannelPressure::updateAllWith(midimsg);
    EXPECT_EQ(vu.getValue(), 0x0);
    bank.setBankSetting(1);
    EXPECT_EQ(vu.getValue(), 0xA);
}

TEST(MCUVUBankable, setValueBankChangeChannel) {
    constexpr uint8_t channel = 3;
    constexpr uint8_t track = 5;
    MCU_VU_Bankable<3> vu(track, channel);
    Bank bank(4);
    bank.add(vu, Bank::CHANGE_CHANNEL);
    MIDI_message_matcher midimsg1 = {CHANNEL_PRESSURE, channel + 4 - 1,
                                     (track - 1) << 4 | 0xA, 0};
    MIDI_message_matcher midimsg2 = {CHANNEL_PRESSURE, channel + 8 - 1,
                                     (track - 1) << 4 | 0xB, 0};
    EXPECT_CALL(ArduinoMock::getInstance(), millis())
        .WillOnce(Return(0))
        .WillOnce(Return(0));
    MIDI_Input_ChannelPressure::updateAllWith(midimsg1);
    MIDI_Input_ChannelPressure::updateAllWith(midimsg2);
    EXPECT_EQ(vu.getValue(), 0x0);
    bank.setBankSetting(1);
    EXPECT_EQ(vu.getValue(), 0xA);
    bank.setBankSetting(2);
    EXPECT_EQ(vu.getValue(), 0xB);
}

TEST(MCUVUBankable, overloadBankChangeAddress) {
    constexpr uint8_t channel = 3;
    constexpr uint8_t track = 5;
    MCU_VU_Bankable<2> vu(track, channel);
    Bank bank(4);
    bank.add(vu, Bank::CHANGE_ADDRESS);
    EXPECT_FALSE(vu.getOverload());
    bank.setBankSetting(1);
    EXPECT_FALSE(vu.getOverload());
    MIDI_message_matcher midimsgSet = {CHANNEL_PRESSURE, channel - 1,
                                       (track + 4 - 1) << 4 | 0xE, 0};
    MIDI_Input_ChannelPressure::updateAllWith(midimsgSet);
    bank.setBankSetting(0);
    EXPECT_FALSE(vu.getOverload());
    bank.setBankSetting(1);
    EXPECT_TRUE(vu.getOverload());
    MIDI_message_matcher midimsgClr = {CHANNEL_PRESSURE, channel - 1,
                                       (track + 4 - 1) << 4 | 0xF, 0};
    MIDI_Input_ChannelPressure::updateAllWith(midimsgClr);
    bank.setBankSetting(0);
    EXPECT_FALSE(vu.getOverload());
    bank.setBankSetting(1);
    EXPECT_FALSE(vu.getOverload());
}

TEST(MCUVUBankable, decay) {
    constexpr uint8_t channel = 3;
    constexpr uint8_t track = 5;
    constexpr unsigned int decayTime = 300;
    MCU_VU_Bankable<2> vu(track, channel, decayTime);
    Bank bank(4);
    bank.add(vu, Bank::CHANGE_ADDRESS);
    MIDI_message_matcher midimsg = {CHANNEL_PRESSURE, channel - 1,
                                    (track + 4 - 1) << 4 | 0xA, 0};
    EXPECT_CALL(ArduinoMock::getInstance(), millis()).WillOnce(Return(0));
    MIDI_Input_ChannelPressure::updateAllWith(midimsg);
    EXPECT_EQ(vu.getValue(), 0x0);
    bank.setBankSetting(1);
    EXPECT_EQ(vu.getValue(), 0xA);
    EXPECT_CALL(ArduinoMock::getInstance(), millis())
        .WillOnce(Return(decayTime));
    MIDI_Input_ChannelPressure::updateAll();
    bank.setBankSetting(0);
    EXPECT_EQ(vu.getValue(), 0x0);
    bank.setBankSetting(1);
    EXPECT_EQ(vu.getValue(), 0x9);
}