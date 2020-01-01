#ifndef GTKMM_EXAMPLE_TREEMODEL_DND_H
#define GTKMM_EXAMPLE_TREEMODEL_DND_H

#include <gtkmm.h>
#include "ModelColumns.h"

//class TreeModel_Dnd : public Gtk::TreeStore
class TreeModel_Dnd : public Gtk::ListStore
{
protected:
  TreeModel_Dnd();

public:
/*
  //Tree model columns:
  class ModelColumns : public Gtk::TreeModel::ColumnRecord
  {
  public:

    ModelColumns()
    { add(m_col_id); add(m_col_name); add(m_col_draggable); add(m_col_receivesdrags); }

    Gtk::TreeModelColumn<int> m_col_id;
    Gtk::TreeModelColumn<Glib::ustring> m_col_name;
    Gtk::TreeModelColumn<int> m_col_number;
    Gtk::TreeModelColumn<int> m_col_percentage;    
    Gtk::TreeModelColumn<bool> m_col_draggable;
    Gtk::TreeModelColumn<bool> m_col_receivesdrags;
  };
*/

  ModelColumns m_Columns;

  static Glib::RefPtr<TreeModel_Dnd> create();

protected:
  //Overridden virtual functions:
  bool row_draggable_vfunc(const Gtk::TreeModel::Path& path) const override;
  bool row_drop_possible_vfunc(const Gtk::TreeModel::Path& dest, const Gtk::SelectionData& selection_data) const override;

};

#endif //GTKMM_EXAMPLE_TREEMODEL_DND_H
