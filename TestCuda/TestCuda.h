#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TestCuda.h"

class TestCuda : public QMainWindow
{
	Q_OBJECT

public:
	TestCuda(QWidget *parent = Q_NULLPTR);

private:
	Ui::TestCudaClass ui;
};
