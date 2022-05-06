#include "SettingsDialog.h"

#include <QGridLayout>
#include <QSpinBox>
#include <QLabel>

#include <QCloseEvent>

#include "core/SettingsManager.h"
#include "core/InfoProvider.h"
#include "SelectColorButton.h"

inline constexpr auto graphLengthName = "graphLength";
inline constexpr auto graphUpdateFrequencyName = "graphUpdateFrequency";

inline QString getColorButtonName(int gpuIndex) {
    return "colorButton_" + QString::number(gpuIndex);
}

SettingsDialog::SettingsDialog() {
    setWindowTitle("Settings");

    auto layout = new QGridLayout();
    layout->setAlignment(Qt::AlignTop);

    auto spinBoxValue = [&](const QString &name, const QString &spinBoxName, int min, int max, int step, int val)
    {
        auto spinBox = new QSpinBox();
        spinBox->setObjectName(spinBoxName);
        spinBox->setMinimum(min);
        spinBox->setMaximum(max);
        spinBox->setSingleStep(step);
        spinBox->setValue(val);

        auto row = layout->rowCount();
        layout->addWidget(new QLabel(name), row, 0);
        layout->addWidget(spinBox, row, 1);

        return spinBox;
    };

    layout->addWidget(new QLabel("<b>Basic</b>"));

    spinBoxValue("Graph length (ms)", graphLengthName, 1000, 7200000, 5000, SettingsManager::getGraphLength());
    spinBoxValue("Update frequency (ms)", graphUpdateFrequencyName, 10, 7200000, 100, SettingsManager::getUpdateDelay());

    layout->addWidget(new QLabel("<br><b>Colors</b>"));

    for (int i = 0; i < InfoProvider::getGPUCount(); i++) {
        auto colorButton = new SelectColorButton(SettingsManager::getGPUColor(i));
        colorButton->setObjectName(getColorButtonName(i));

        auto row = layout->rowCount();
        layout->addWidget(new QLabel(InfoProvider::getGPUName(i)), row, 0);
        layout->addWidget(colorButton, row, 1);
    }

    setLayout(layout);
}

void SettingsDialog::closeEvent(QCloseEvent *event) {
    SettingsManager::setGraphLength(findChild<QSpinBox*>(graphLengthName)->value());
    SettingsManager::setUpdateDelay(findChild<QSpinBox*>(graphUpdateFrequencyName)->value());

    for (int i = 0; i < InfoProvider::getGPUCount(); i++) {
        SettingsManager::setGPUColor(i, findChild<SelectColorButton*>(getColorButtonName(i))->getColor());
    }

    SettingsManager::save();

    event->accept();
}
