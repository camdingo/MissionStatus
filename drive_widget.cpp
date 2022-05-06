#include "drive_widget.h"

#include <QVBoxLayout>

DriveWidget::DriveWidget(QWidget* parent)
	: QWidget(parent)
{
	setupLayout();
}

void DriveWidget::setupLayout()
{
	QVBoxLayout* vLayout = new QVBoxLayout(this);

}

DriveWidget::~DriveWidget()
{
}
