//! @file

#include "SumWidget.hpp"

#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QRandomGenerator>

SumWidget::SumWidget(QWidget* parent)
	: QWidget(parent) {
		_setupWidget();
	}

void
SumWidget::refreshNumberOne() {
 static QRandomGenerator prng(1234);
 _numberOne->setValue(prng.generate() % 10u + 1u);
}

void
SumWidget::refreshNumberTwo() {
 static QRandomGenerator prng(5678);
 _numberTwo->setValue(prng.generate() % 10u + 1u);
}

void
SumWidget::resetResult() {
 _result->setText("?");
}

void
SumWidget::showResult() {
 _result->setText(QString::number(_numberOne->value() + _numberTwo->value()));
}

void
SumWidget::_setupWidget() {
	setObjectName("SumWidget");
	setLayout(new QVBoxLayout(this));
	layout()->setAlignment(Qt::AlignJustify);

	// First row
	// Nb1 '+' Nb2 '=' Res
	{
		QHBoxLayout* hBox = new QHBoxLayout();
		hBox->setAlignment(Qt::AlignJustify);

		_numberOne = new QSpinBox(this);
		connect(
				_numberOne, QOverload<int>::of(&QSpinBox::valueChanged),
				this, &SumWidget::resetResult);
		hBox->addWidget(_numberOne);

		QLabel* plus = new QLabel(this);
		plus->setText("+");
		hBox->addWidget(plus);

		_numberTwo = new QSpinBox(this);
		connect(
				_numberTwo, QOverload<int>::of(&QSpinBox::valueChanged),
				this, &SumWidget::resetResult);
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
		connect(
				randomButton, &QPushButton::clicked,
				[=]() {
				refreshNumberOne();
				refreshNumberTwo();
				});
		hBox->addWidget(randomButton);

		QPushButton* resultButton = new QPushButton("Result", this);
		resultButton->setShortcut(QKeySequence::HelpContents); // F1
		connect(resultButton, &QPushButton::clicked, this, &SumWidget::showResult);
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
