//! @file

#include "MultiplyWidget.hpp"

#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <QVBoxLayout>

MultiplyWidget::MultiplyWidget(QWidget* parent) : QWidget(parent), _generator(), _distribution(1, 10) {
  std::random_device rd; // Will be used to obtain a seed for the random number engine
  _generator.seed(rd());

  _setupWidget();
}

void MultiplyWidget::refreshNumberOne() {
  _numberOne->setValue(_distribution(_generator));
}

void MultiplyWidget::refreshNumberTwo() {
  _numberTwo->setValue(_distribution(_generator));
}

void MultiplyWidget::resetResult() {
  _result->setText("?");
}

void MultiplyWidget::showResult() {
  _result->setText(QString::number(_numberOne->value() * _numberTwo->value()));
}

void MultiplyWidget::_setupWidget() {
  setObjectName("MultiplyWidget");
  setLayout(new QVBoxLayout(this));
  layout()->setAlignment(Qt::AlignJustify);

  // First row
  // Nb1 '+' Nb2 '=' Res
  {
    QHBoxLayout* hBox = new QHBoxLayout();
    hBox->setAlignment(Qt::AlignJustify);

    _numberOne = new QSpinBox(this);
    connect(_numberOne, QOverload<int>::of(&QSpinBox::valueChanged), this, &MultiplyWidget::resetResult);
    hBox->addWidget(_numberOne);

    QLabel* plus = new QLabel(this);
    plus->setText("x");
    hBox->addWidget(plus);

    _numberTwo = new QSpinBox(this);
    connect(_numberTwo, QOverload<int>::of(&QSpinBox::valueChanged), this, &MultiplyWidget::resetResult);
    hBox->addWidget(_numberTwo);

    QLabel* equal = new QLabel(this);
    equal->setText("=");
    hBox->addWidget(equal);

    _result = new QLabel(this);
    _result->setText("");
    hBox->addWidget(_result);

    layout()->addItem(hBox);
  }

  // Second row
  // [Refresh] | [Result]
  {
    QHBoxLayout* hBox = new QHBoxLayout();
    hBox->setAlignment(Qt::AlignJustify);

    QPushButton* randomButton = new QPushButton("Random", this);
    randomButton->setShortcut(QKeySequence::Refresh); // F5
    connect(randomButton, &QPushButton::clicked, [=]() {
      refreshNumberOne();
      refreshNumberTwo();
    });
    hBox->addWidget(randomButton);

    QPushButton* resultButton = new QPushButton("Result", this);
    resultButton->setShortcut(QKeySequence::HelpContents); // F1
    connect(resultButton, &QPushButton::clicked, this, &MultiplyWidget::showResult);
    hBox->addWidget(resultButton);

    layout()->addItem(hBox);
  }

  { // Quit button at bottom
    QSpacerItem* spacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout()->addItem(spacer);

    QPushButton* quitButton = new QPushButton("Quit", this);
    quitButton->setShortcut(QKeySequence::Quit);
    connect(quitButton, &QPushButton::clicked, qApp, &QApplication::quit);
    layout()->addWidget(quitButton);
  }
}
