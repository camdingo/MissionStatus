#ifndef SUMMARY_VIEW_H
#define SUMMARY_VIEW_H

#include <QWidget>

class QLabel;


class SummaryView: public QWidget
{
	Q_OBJECT
	
	static const QString RED_BACKGROUND;
	static const QString YELLOW_BACKGROUND;
	static const QString GREEN_BACKGROUND;

public:
	SummaryView(QWidget* parent);
	~SummaryView();
	
	void setupLayout();
	void createConnections();

private:
	QLabel* _wksLabel;
	QLabel* _serversLabel;
	QLabel* _drivesLabel;

};

#endif //SUMMARY_VIEW_H
