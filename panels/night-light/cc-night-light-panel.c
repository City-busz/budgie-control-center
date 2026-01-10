/*
 * Copyright (C) 2026 Buddies of Budgie
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include "cc-night-light-panel.h"
#include "cc-night-light-resources.h"
#include "cc-night-light-page.h"

#include <glib/gi18n.h>
#include <gtk/gtk.h>

struct _CcNightLightPanel
{
  CcPanel parent_instance;

  CcNightLightPage *night_light_page;
};

CC_PANEL_REGISTER (CcNightLightPanel, cc_night_light_panel)

static void
cc_night_light_panel_class_init (CcNightLightPanelClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  g_type_ensure (CC_TYPE_NIGHT_LIGHT_PAGE);

  gtk_widget_class_set_template_from_resource (widget_class, "/org/gnome/control-center/night-light/cc-night-light-panel.ui");

  gtk_widget_class_bind_template_child (widget_class, CcNightLightPanel, night_light_page);
}

static void
cc_night_light_panel_init (CcNightLightPanel *self)
{
  g_resources_register (cc_night_light_get_resource ());

  gtk_widget_init_template (GTK_WIDGET (self));
}

