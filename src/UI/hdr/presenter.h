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
  Presenter(MainWindow *v, std::unique_ptr<API::IEXInterface> &iex);

public slots:
  void onStockButtonClicked();

private:
  virtual void updateStockMessage(const std::string &message);

  MainWindow *m_view = nullptr;
  std::unique_ptr<API::IEXInterface> m_iex;
  std::shared_ptr<spdlog::logger> m_logger;
};
} // UI