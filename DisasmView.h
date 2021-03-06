#pragma once

#include <QAbstractScrollArea>

#include <vector>
#include "DebugCore.h"

class DebugCore;

class DisasmView : public QAbstractScrollArea
{
    Q_OBJECT
public:
    explicit DisasmView(QWidget *parent = 0);
    ~DisasmView();

public slots:
    void gotoAddress(uint64_t address);
    void setRegion(uint64_t address);
    void analysis();
    void setDebugCore(std::shared_ptr<DebugCore> debugCore);
	void updateContent();
protected:
    void paintEvent(QPaintEvent *e) override;
	void mousePressEvent(QMouseEvent *event) override;
	virtual void wheelEvent(QWheelEvent *event) override;

private:
    uint64_t m_regionStart;
    uint64_t m_regionSize;

    std::vector<uint64_t> m_insnStart;

    uint64_t m_currentAddress;
    bool m_foundIndex;

	std::weak_ptr<DebugCore> m_debugCore;
};

