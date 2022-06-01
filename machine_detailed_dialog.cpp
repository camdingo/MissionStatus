#include "machine_detailed_dialog.h"

#include <QVBoxLayout>
#include <QLabel>


MachineDetailedDialog::MachineDetailedDialog(QWidget* parent)
	: QDialog(parent)
{
	_cpu = new CpuWidget(this);
	_ram = new RamWidget(this);

	setupLayout();
}

void MachineDetailedDialog::setupLayout()
{

}

MachineDetailedDialog::~MachineDetailedDialog()
{
}
