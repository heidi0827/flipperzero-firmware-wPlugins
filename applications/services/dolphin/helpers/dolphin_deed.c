#include "dolphin_deed.h"
#include <furi.h>

static const DolphinDeedWeight dolphin_deed_weights[] = {
    {25, DolphinAppSubGhz}, // DolphinDeedSubGhzReceiverInfo
    {50, DolphinAppSubGhz}, // DolphinDeedSubGhzSave
    {25, DolphinAppSubGhz}, // DolphinDeedSubGhzRawRec
    {50, DolphinAppSubGhz}, // DolphinDeedSubGhzAddManually
    {50, DolphinAppSubGhz}, // DolphinDeedSubGhzSend
    {25, DolphinAppSubGhz}, // DolphinDeedSubGhzFrequencyAnalyzer

    {25, DolphinAppRfid}, // DolphinDeedRfidRead
    {50, DolphinAppRfid}, // DolphinDeedRfidReadSuccess
    {50, DolphinAppRfid}, // DolphinDeedRfidSave
    {50, DolphinAppRfid}, // DolphinDeedRfidEmulate
    {50, DolphinAppRfid}, // DolphinDeedRfidAdd

    {25, DolphinAppNfc}, // DolphinDeedNfcRead
    {50, DolphinAppNfc}, // DolphinDeedNfcReadSuccess
    {25, DolphinAppNfc}, // DolphinDeedNfcSave
    {25, DolphinAppNfc}, // DolphinDeedNfcDetectReader
    {50, DolphinAppNfc}, // DolphinDeedNfcEmulate
    {50, DolphinAppNfc}, // DolphinDeedNfcMfcAdd
    {25, DolphinAppNfc}, // DolphinDeedNfcAddSave
    {25, DolphinAppNfc}, // DolphinDeedNfcAddEmulate

    {25, DolphinAppIr}, // DolphinDeedIrSend
    {50, DolphinAppIr}, // DolphinDeedIrLearnSuccess
    {50, DolphinAppIr}, // DolphinDeedIrSave

    {25, DolphinAppIbutton}, // DolphinDeedIbuttonRead
    {50, DolphinAppIbutton}, // DolphinDeedIbuttonReadSuccess
    {50, DolphinAppIbutton}, // DolphinDeedIbuttonSave
    {50, DolphinAppIbutton}, // DolphinDeedIbuttonEmulate
    {50, DolphinAppIbutton}, // DolphinDeedIbuttonAdd

    {50, DolphinAppBadusb}, // DolphinDeedBadUsbPlayScript
    {50, DolphinAppPlugin}, // DolphinDeedU2fAuthorized

    {25, DolphinAppPlugin}, // DolphinDeedGpioUartBridge

    {25, DolphinAppPlugin}, // DolphinDeedPluginStart
    {25, DolphinAppPlugin}, // DolphinDeedPluginGameStart
    {50, DolphinAppPlugin}, // DolphinDeedPluginGameWin
};

static uint8_t dolphin_deed_limits[] = {
    200, // DolphinAppSubGhz
    200, // DolphinAppRfid
    200, // DolphinAppNfc
    200, // DolphinAppIr
    200, // DolphinAppIbutton
    200, // DolphinAppBadusb
    // 100, // DolphinAppU2f
    // 100, // DolphinAppGpio
    200, // DolphinAppPlugin
};

_Static_assert(COUNT_OF(dolphin_deed_weights) == DolphinDeedMAX, "dolphin_deed_weights size error");
_Static_assert(COUNT_OF(dolphin_deed_limits) == DolphinAppMAX, "dolphin_deed_limits size error");

uint8_t dolphin_deed_get_weight(DolphinDeed deed) {
    furi_check(deed < DolphinDeedMAX);
    return dolphin_deed_weights[deed].icounter;
}

DolphinApp dolphin_deed_get_app(DolphinDeed deed) {
    furi_check(deed < DolphinDeedMAX);
    return dolphin_deed_weights[deed].app;
}

uint8_t dolphin_deed_get_app_limit(DolphinApp app) {
    furi_check(app < DolphinAppMAX);
    return dolphin_deed_limits[app];
}
