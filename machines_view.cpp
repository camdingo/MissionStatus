#include "machines_view.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QDebug>

MachinesView::MachinesView(QWidget* parent, QStringList const& machines)
	: QWidget(parent)
	, _machineList(machines)
{

	getBases();
	getWks();
	//getServers();
	//getMisc();
	
	setupLayout();
}

void MachinesView::getBases()
{
	int baseIndex = _machineList.indexOf("#Base") + 1;
	for(; baseIndex != _machineList.size(); ++baseIndex)
	{
		if(_machineList.at(baseIndex).contains("#"))
			return;
			
		_bases << _machineList.at(baseIndex);
	}
}

void MachinesView::getWks()
{
	int wksIndex = _machineList.indexOf("#Workstations") + 1;

	for(; wksIndex != _machineList.size(); ++wksIndex)
	{
		if(_machineList.at(wksIndex).contains("#"))
			return;
			
		_wks << _machineList.at(wksIndex);
	}
}

void MachinesView::getServers()
{
	int serverIndex = _machineList.indexOf("#Server");
}

void MachinesView::getMisc()
{
	int miscIndex = _machineList.indexOf("#Misc");
}


void MachinesView::setupLayout()
{
	QVBoxLayout* layout = new QVBoxLayout(this);

	//Set up base group
	QGroupBox* baseGroup = new QGroupBox("Base", this);
	QHBoxLayout* baseLayout = new QHBoxLayout(baseGroup);
	foreach(auto base, _bases)
	{	
		if(base.isEmpty())
			continue;
		
		MachineWidget* machineWidget = new MachineWidget(this, base);
		baseLayout->addWidget(machineWidget);
	}
	baseGroup->setLayout(baseLayout);
	layout->addWidget(baseGroup);
	
	//Set up Workstation group
	QGroupBox* wksGroup = new QGroupBox("Workstations", this);
	QHBoxLayout* wksLayout = new QHBoxLayout(wksGroup);
	foreach(auto wks, _wks)
	{	
		if(wks.isEmpty())
			continue;
		
		qDebug() << "workst" << wks;
		MachineWidget* machineWidget = new MachineWidget(this, wks);
		wksLayout->addWidget(machineWidget);
	}
	wksGroup->setLayout(wksLayout);
	layout->addWidget(wksGroup);
		
	/*
	foreach(auto server, _servers)
	{	
		if(server.isEmpty())
			continue;
		
		MachineWidget* machineWidget = new MachineWidget(this, server);
		layout->addWidget(machineWidget);
	}
	*/
}

MachinesView::~MachinesView()
{
}
