/** @file
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef DISSECTOR_TABLES_DIALOG_H
#define DISSECTOR_TABLES_DIALOG_H

#include <ui/qt/geometry_state_dialog.h>
#include <ui/qt/models/dissector_tables_model.h>

namespace Ui {
class DissectorTablesDialog;
}

class DissectorTablesDialog : public GeometryStateDialog
{
    Q_OBJECT

public:
    explicit DissectorTablesDialog(QWidget *parent = 0);
    ~DissectorTablesDialog();

private slots:
    void on_txtSearchLine_textChanged(const QString &search_re);

private:
    Ui::DissectorTablesDialog *ui;

    DissectorTablesProxyModel* proxyModel_;
};

#endif // DISSECTOR_TABLES_DIALOG_H
