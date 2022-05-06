#include "machines_view.h"

#include <QVBoxLayout>
#include <QDebug>

MachinesView::MachinesView(QWidget* parent, QStringList const& machines)
	: QWidget(parent)
{
	foreach(auto machine, machines)
	{
		if(machine.contains("#Base"))
			_bases << machine;
		else if(machine.contains("#Workstations"))
			_wks << machine;	
		else if(machine.contains("#Servers"))
			_servers << machine;
		else
			_misc << machine;
	}

	setupLayout();
}

void MachinesView::setupLayout()
{
	QVBoxLayout* vLayout = new QVBoxLayout(this);
	
	//add MachineWidgets
	foreach(auto base, _bases)
	{	
		if(base.isEmpty())
			continue;
		
		MachineWidget* machineWidget = new MachineWidget(this, base);
		vLayout->addWidget(machineWidget);
	}
	
}

MachinesView::~MachinesView()
{
}
