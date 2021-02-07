#include "mode_controller.h"
ModeController::ModeController(QObject *parent):
    QObject(parent){
    mode2 =new Medium(this);
}
ModeController::~ModeController(){}

int ModeController::mode2Slot(const int *progressArray, int progress, QString data){
    return mode2 ->getSlot(progressArray, progress, data);
}
