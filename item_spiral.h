/**
 *  @brief
 *  @details
 *  @author    Ludovic A.
 *  @date      2015 /2016/2017
 *  @bug       No known bugs
 *  @copyright GNU Public License v3
 */

#ifndef ITEM_SPIRAL_H
#define ITEM_SPIRAL_H

#include <QAbstractGraphicsShapeItem>
#include <QKeyEvent>
#include <QPainterPath>
#include <QRectF>
#include <QXmlStreamWriter>

#include "gribouillotitem.h"

class Item_spiral : public QAbstractGraphicsShapeItem
{
public:
    enum { Type = SPIRAL };
    int type() const
    {
        // Enable the use of qgraphicsitem_cast with this item.
        return SPIRAL;
    }
    explicit Item_spiral(QVector<QPointF> base, QColor penColor = Qt::black, int penWidth = 3);
    ~Item_spiral(){}

    void newPen(QColor penColor, int penWidth);
    static QRectF computeArcRect(int sideNumber, QVector<QLineF> side);
    static void computeArcAngles(QLineF side1, QLineF side2,
                                 qreal &startAngle, qreal &spanAngle);
    void serialize2xml(QXmlStreamWriter* w);
    QString status(qreal scale);

protected:
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

private:
    QVector<QLineF> baseSide;
    QVector<QRectF> arcsRect;

    bool clockwise;
    qreal selectionMargin;

};

#endif