#ifndef GO_HELP_H
#define GO_HELP_H

#include <iostream>

/**
 * Help.
 */
class Help {

 public :

  /**
   * Вывести на экран Help
   */
  void printHelp() const noexcept;

 private :

  /**
   * Вывести сообщение хэлпа
   */
  void printConsoleArgs() const noexcept;

  /**
   * Вывести сообщение хэлпа
   */
  void printCommandsForConsoleArgs() const noexcept;

  /**
   * Вывести сообщение хэлпа
   */
  void printTitle() const noexcept;

  /**
   * Вывести сообщение хэлпа
   */
  void printAllStepsOfGame() const noexcept;

  /**
   * Вывести сообщение хэлпа
   */
  void printGameProcessOnly() const noexcept;

  /**
   * Вывести сообщение хэлпа
   */
  void printExit() const noexcept;

  /**
   * Вывести сообщение хэлпа
   */
  void printPass() const noexcept;

  /**
   * Вывести сообщение хэлпа
   */
  void printSurrender() const noexcept;

  /**
   * Вывести сообщение хэлпа
   */
  void printMove() const noexcept;

  /**
   * Вывести сообщение хэлпа
   */
  void emptyLine() const noexcept;

  /**
   * Вывести сообщение хэлпа
   */
  void printSmthAbtGame() const noexcept;
};


#endif //GO_HELP_H
