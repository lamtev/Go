#ifndef GO_SETTINGS_H
#define GO_SETTINGS_H

#include <QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QPushButton>

class Settings : public QWidget {
 Q_OBJECT

 public:
  explicit Settings(QWidget *parent = nullptr) noexcept;

 private:
  QPalette *settingsPalette;
  QLabel *text;
  QRadioButton *rButton19x19;
  QRadioButton *rButton13x13;
  QRadioButton *rButton7x7;
  QPushButton *buttonReturnToMenu;
  QPushButton *buttonSaveSettings;

  void configureSettingsPalette() noexcept;
  void configureButtons() noexcept;
  void configureRButton19x19() noexcept;
  void configureRButton13x13() noexcept;
  void configureRButton7x7() noexcept;
  void configureButtonReturnToMenu() noexcept;
  void configureButtonSaveSettings() noexcept;

 signals:

 private slots:
  void slotSaveSettings() noexcept {};

};

#endif //GO_SETTINGS_H
