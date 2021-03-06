/** @file
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef SPARKLINE_DELEGATE_H
#define SPARKLINE_DELEGATE_H

#include <QStyledItemDelegate>

class SparkLineDelegate : public QStyledItemDelegate
{
public:
    SparkLineDelegate(QWidget *parent = 0) : QStyledItemDelegate(parent) {}

protected:
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

signals:

public slots:

};

Q_DECLARE_METATYPE(QList<int>)

#endif // SPARKLINE_DELEGATE_H
