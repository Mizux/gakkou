//! @file
#pragma once

#include <QLabel>
#include <QSpinBox>
#include <QWidget>
#include <random>

//! @brief Mesh Viewer.
class MultiplyWidget : public QWidget {
  Q_OBJECT
 public:
  //! @brief Default constructor.
  //! @param[in] parent Parent widget if any.
  explicit MultiplyWidget(QWidget* parent = nullptr);
  ~MultiplyWidget() = default;
  //! @brief disable copy constructor.
  MultiplyWidget(const MultiplyWidget&) = delete;
  //! @brief disable copy operator.
  //! @return This Viewer instance.
  MultiplyWidget& operator=(const MultiplyWidget&) = delete;
  //! @brief disable move constructor.
  MultiplyWidget(const MultiplyWidget&&) = delete;
  //! @brief disable move operator.
  //! @return This Viewer instance.
  MultiplyWidget& operator=(const MultiplyWidget&&) = delete;

 public slots:
  void refreshNumberOne();
  void refreshNumberTwo();
  void resetResult();
  void showResult();

  // signal:

 private:
  //! @brief First number to sum.
  QSpinBox* _numberOne;
  //! @brief Second number to sum.
  QSpinBox* _numberTwo;
  //! @brief Display the rsult.
  QLabel* _result;

  std::mt19937                    _generator; // Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> _distribution;

  //! @brief Internal function to setup the widget.
  void _setupWidget();
};
