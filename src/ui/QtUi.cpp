#include "QtUi.hpp"
#include "MainWindow/MainWindow.hpp"

QtUi::QtUi(int ac, char *av[]) : QApplication(ac, av) {
  MainWindow *mw = new MainWindow();
  mw->setAttribute(Qt::WA_DeleteOnClose, true);

  connect(mw, &QObject::destroyed, this, [&]() { this->_shouldStop = true; });
  mw->show();
}

QtUi::~QtUi() { quit(); }

void QtUi::processEvent() { QCoreApplication::processEvents(); }

bool QtUi::shouldStop() { return _shouldStop; }
