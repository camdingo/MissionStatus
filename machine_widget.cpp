#include "machine_widget.h"

#include <QVBoxLayout>
#include <QLabel>

MachineWidget::MachineWidget(QWidget* parent, QString name)
	: QWidget(parent)
	, _machineName(name)
{
	//TODO pass machine name to widgets so we know where to go to get the correct info

	_cpu = new CpuWidget(this);
	_ram = new RamWidget(this);
	
	setupLayout();
}

void MachineWidget::setupLayout()
{
	QVBoxLayout* vLayout = new QVBoxLayout(this);
	
	QLabel* name = new QLabel(_machineName);

	vLayout->addWidget(name);
	vLayout->addWidget(_cpu);
	vLayout->addWidget(_ram);
	
	//
	//add gpu widget
}

MachineWidget::~MachineWidget()
{
}
