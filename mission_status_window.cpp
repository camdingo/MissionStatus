#include "mission_status_window.h"

#include <QTabWidget>
#include <QStatusBar>
#include <QMenuBar>
#include <QDebug>
#include <QStringList>

#include "boost/filesystem.hpp"
#include "boost/filesystem/fstream.hpp"

#include "summary_view.h"
#include "drives_view.h"
#include "machines_view.h"

MissionStatus::MissionStatus()
{
	createMenuBar();
	createStatusBar();
	
	readCfgs();
	
	setupLayout();
}

void MissionStatus::setupLayout()
{
	//Init main widget
	_tabWidget = new QTabWidget(this);
	
	//setup all the tabs
	setupTabs();
	
	//set main widget
	setCentralWidget(_tabWidget);

}

void MissionStatus::readCfgs()
{
	namespace fs = boost::filesystem;
	std::string tmp;
	fs::path machinesPath{ "../machines.cfg" };
	
	//Read machines
	fs::ifstream fileHandler(machinesPath);
	std::string line;
	while (getline(fileHandler, line)) {
		if(!line.empty()) //skip empty lines
    			_machines << QString::fromStdString(line);
	}
	
	fileHandler.close();
	
	//Read drives
	fs::path drivesPath{ "../drives.cfg" };
	fileHandler.open(drivesPath);
	while (getline(fileHandler, line)) {
		if(!line.empty()) //skip empty lines
    			_drives << QString::fromStdString(line);
    	}
    	
	fileHandler.close();
}

void MissionStatus::setupTabs()
{

	SummaryView* summaryView = new SummaryView(this);
	_tabWidget->addTab(summaryView, "Summary");
	
	DrivesView* drivesView = new DrivesView(this, _drives);
	_tabWidget->addTab(drivesView, "Drives");

	MachinesView* machinesView = new MachinesView(this, _machines);
	_tabWidget->addTab(machinesView, "Machines");
}


void MissionStatus::createMenuBar()
{
	_fileMenu = new QMenu("&File");
	_exitAppAction = new QAction("Exit");
	
	_fileMenu->addAction(_exitAppAction);

	connect(_exitAppAction, SIGNAL(triggered()), this, SLOT(close()));

	menuBar()->addMenu(_fileMenu);
}

void MissionStatus::createStatusBar()
{
	statusBar()->showMessage(tr("Ready"));
}

MissionStatus::~MissionStatus()
{
}
