#ifndef QTUI_HPP
#define QTUI_HPP

#include <QApplication>

#include "IUi.hpp"

class QtUi final : public QApplication, public IUi {
 public:
  QtUi(int ac, char *av[]);
  ~QtUi();

  void processEvent() final;
  bool shouldStop() final;

 private:
  bool _shouldStop{false};
};

#endif  // QTUI_HPP
