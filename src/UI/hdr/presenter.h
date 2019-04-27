#include <QObject>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include "mainwindow.h"
#include "../../API/hdr/IEX.h"

namespace UI {
class Presenter : public QObject {
  Q_OBJECT
public:
  Presenter(MainWindow *v);

public slots:
  void onViewButtonClicked();

private:
  MainWindow *m_view = nullptr;
  API::IEX m_iex;
  std::shared_ptr<spdlog::logger> m_logger;
};
} // UI