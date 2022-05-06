#include "summary_view.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>

const QString SummaryView::RED_BACKGROUND = "QLabel { background-color : red; }";
const QString SummaryView::YELLOW_BACKGROUND = "QLabel { background-color : yellow; }";
const QString SummaryView::GREEN_BACKGROUND = "QLabel { background-color : green; }";

SummaryView::SummaryView(QWidget* parent)
	: QWidget(parent)
{
	setupLayout();
	
	createConnections();
}

SummaryView::~SummaryView()
{

}

void SummaryView::setupLayout()
{
	QHBoxLayout* layout = new QHBoxLayout();
	
	//Setup Workstations
	QPixmap wksImage("../images/pc.png");
	_wksLabel = new QLabel;
	_wksLabel->setStyleSheet(RED_BACKGROUND);
	_wksLabel->setPixmap(wksImage);

	//Setup Servers
	QPixmap serversImage("../images/server.png");
	_serversLabel = new QLabel;
	_serversLabel->setStyleSheet(YELLOW_BACKGROUND);
	_serversLabel->setPixmap(serversImage);
	
	//Setup Drives
	QPixmap drivesImage("../images/drive.png");
	_drivesLabel = new QLabel;
	_drivesLabel->setStyleSheet(GREEN_BACKGROUND);
	_drivesLabel->setPixmap(drivesImage);


	layout->addWidget(_wksLabel);
	layout->addWidget(_serversLabel);
	layout->addWidget(_drivesLabel);
	
	setLayout(layout);
}

void SummaryView::createConnections()
{
	//connect other tabs to the labels to modify color and possibly tooltip?
	//maybe have audio alert if something changes to yellow or red
}
