/***

  Olive - Non-Linear Video Editor
  Copyright (C) 2019 Olive Team

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

***/

#ifndef WIDGETMENU_H
#define WIDGETMENU_H

#include <QMenuBar>
#include <QMenu>

/**
 * @brief A menu widget for context menus and menu bars
 *
 * A QMenu subclass with functions for creating menus and menu items that conform to Olive's menu and keyboard shortcut
 * system.
 *
 * In Olive, menu items in the menu bar are also responsible for keyboard shortcuts throughout the application. To allow
 * these to be configurable and these configurations saveable, every item needs a unique ID. This ID gets linked to the
 * keyboard shortcuts in config files. The ID doesn't get translated so it can also persist through language changes.
 *
 * The ID gets stored in the QAction's "id" property. If a keyboard shortcut is provided, it gets stored in the
 * QAction's "keydefault" property.
 *
 * It is always recommended to use this over QMenu in any situation.
 */
class Menu : public QMenu
{
public:
  /**
   * @brief Construct a Menu and add it to a QMenuBar
   *
   * This Menu can be connected to a slot that's triggered when the Menu is "about to show". Use `receiver` and
   * `member` to connect this (same syntax as QObject::connect) or leave as nullptr to not.
   */
  Menu(QMenuBar* bar, const QObject* receiver = nullptr, const char* member = nullptr);

  /**
   * @brief Construct a Menu and add it as a submenu to another Menu
   *
   * This Menu can be connected to a slot that's triggered when the Menu is "about to show". Use `receiver` and
   * `member` to connect this (same syntax as QObject::connect) or leave as nullptr to not.
   */
  Menu(Menu* bar, const QObject* receiver = nullptr, const char* member = nullptr);

  /**
   * @brief Create a menu item and add it to this menu
   *
   * @param id
   *
   * The action's unique ID
   *
   * @param receiver
   *
   * The QObject to receive the signal when this item is triggered
   *
   * @param member
   *
   * The QObject slot to connect this action's triggered signal to
   *
   * @param key
   *
   * Default keyboard sequence
   *
   * @return
   *
   * The QAction that was created and added to this Menu
   */
  QAction* AddItem(const QString& id,
                   const QObject* receiver,
                   const char* member,
                   const QString &key = QString());

  /**
   * @brief Create a menu item
   *
   * @param parent
   *
   * The QAction's parent
   *
   * @param id
   *
   * The action's unique ID
   *
   * @param receiver
   *
   * The QObject to receive the signal when this item is triggered
   *
   * @param member
   *
   * The QObject slot to connect this action's triggered signal to
   *
   * @param key
   *
   * Default keyboard sequence
   *
   * @return
   *
   * The QAction that was created and added to this Menu
   */
  static QAction* CreateItem(QObject* parent,
                             const QString& id,
                             const QObject* receiver,
                             const char* member,
                             const QString& key = QString());

  /**
   * @brief Conform a QAction to Olive's ID/keydefault system
   *
   * If a QAction was created elsewhere (e.g. through QUndoStack::createUndoAction()), this function will give it
   * properties conforming it to Olive's menu item system
   *
   * @param a
   *
   * The QAction's to conform
   *
   * @param id
   *
   * The action's unique ID
   *
   * @param receiver
   *
   * The QObject to receive the signal when this item is triggered
   *
   * @param member
   *
   * The QObject slot to connect this action's triggered signal to
   *
   * @param key
   *
   * Default keyboard sequence
   */
  static void ConformItem(QAction *a,
                          const QString& id,
                          const QObject* receiver,
                          const char* member,
                          const QString& key = QString());

  static void SetBooleanAction(QAction* a, bool *boolean);

private:
  
};

#endif // WIDGETMENU_H
