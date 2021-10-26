#include <memory>

#include "ui/QtUi.hpp"

int main(int argc, char *argv[]) {
  std::unique_ptr<IUi> ui(new QtUi(argc, argv));

  while (!ui->shouldStop()) {
    ui->processEvent();
  }
}
