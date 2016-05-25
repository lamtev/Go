#include "Settings.h"

Settings::Settings(QWidget *parent) noexcept : QWidget{parent},
                                               settingsPalette{nullptr},
                                               text{new QLabel{QObject::tr("Chose board size"), this}},
                                               rButton19x19{new QRadioButton{this}},
                                               rButton13x13{new QRadioButton{this}},
                                               rButton7x7{new QRadioButton{this}},
                                               buttonReturnToMenu{new QPushButton{this}},
                                               buttonSaveSettings{new QPushButton{this}} {
  setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
  setGeometry(QRect{0, 0, 480, 320});
  //resize(QPixmap{":/menu_backgound_small.jpg"}.size());
  //setFixedSize(QSize{480, 320});
  configureSettingsPalette();
  configureButtons();
  text->move((width() - text->width())/2,
             (height() - text->height())/2);
}

void Settings::configureSettingsPalette() noexcept {
  settingsPalette = new QPalette;
  settingsPalette->setBrush(backgroundRole(), QBrush{QPixmap{":/menu_background_small.jpg"}});
}

void Settings::configureButtons() noexcept {
  configureRButton19x19();
  configureRButton13x13();
  configureRButton7x7();
  configureButtonReturnToMenu();
  configureButtonSaveSettings();
}

void Settings::configureRButton19x19() noexcept {
  rButton19x19->setText(QObject::tr("19 x 19"));
}

void Settings::configureRButton13x13() noexcept {
  rButton13x13->setText(QObject::tr("13 x 13"));
}

void Settings::configureRButton7x7() noexcept {
  rButton7x7->setText(QObject::tr(" 7 x 7"));
}

void Settings::configureButtonReturnToMenu() noexcept {
  buttonReturnToMenu->setText(QObject::tr("Return to menu"));
}

void Settings::configureButtonSaveSettings() noexcept {
  buttonSaveSettings->setText(QObject::tr("Save settings"));
}