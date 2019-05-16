#include <QObject>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include "mainwindow.h"
#include "../../API/hdr/IEX.h"

namespace UI {
class Presenter : public QObject {
  Q_OBJECT
public:
  explicit Presenter(std::shared_ptr<MainWindow> v);

public slots:
  void onViewButtonClicked();

private:
  std::shared_ptr<MainWindow> m_view = nullptr;
  API::IEX m_iex;
  std::shared_ptr<spdlog::logger> m_logger;
};
} // UI