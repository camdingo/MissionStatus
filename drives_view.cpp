#include "drives_view.h"

#include <QHBoxLayout>
#include <QLabel>


DrivesView::DrivesView(QWidget* parent, QStringList const& drives)
	: QWidget(parent)
	, _drives(drives)
{
	setupLayout();
}

DrivesView::~DrivesView()
{

}

void DrivesView::setupLayout()
{
	QHBoxLayout* layout = new QHBoxLayout();
	
	QLabel* label = new QLabel("Matt will work");
	layout->addWidget(label);
	
	setLayout(layout);
}
