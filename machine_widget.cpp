#include "machine_widget.h"

#include <QVBoxLayout>
#include <QLabel>

const QString MachineWidget::RED_BACKGROUND = "QLabel { background-color : red; }";
const QString MachineWidget::YELLOW_BACKGROUND = "QLabel { background-color : yellow; }";
const QString MachineWidget::GREEN_BACKGROUND = "QLabel { background-color : green; }";

MachineWidget::MachineWidget(QWidget* parent, QString name)
	: QWidget(parent)
	, _machineName(name)
{
	setupLayout();
}

void MachineWidget::setupLayout()
{
	QVBoxLayout* vLayout = new QVBoxLayout(this);
	
	QLabel* name = new QLabel(_machineName);
	name->setTextFormat(Qt::RichText);
	name->setText("<b>" + _machineName + "<\b> <br><img src=../images/pc.png>");
	name->setStyleSheet(GREEN_BACKGROUND);
	vLayout->addWidget(name);


}

MachineWidget::~MachineWidget()
{
}
