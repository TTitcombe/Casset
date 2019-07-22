#ifndef UI_PRESENTER_H_
#define UI_PRESENTER_H_

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
  explicit Presenter(std::shared_ptr<MainWindow> v, std::unique_ptr<API::IEXInterface> &iex);

public slots:
  void onStockButtonClicked();

private:
  virtual void updateStockMessage(const std::string &message);

  std::shared_ptr<MainWindow> m_view = nullptr;
  std::unique_ptr<API::IEXInterface> m_iex;
  std::shared_ptr<spdlog::logger> m_logger;
};
} // UI
#endif // UI_PRESENTER_H_