/*
 * Xcomtool (Xiyou Linux Group)
 *
 * Copyright (c) 2008-~  Xiyou Linux Group
 *
 * This source code is released for free distribution under the
 * terms of the GNU General Public License.
 *
 * file name: MenuCall.c
 * modify date: 2009-7-30
 * Author: helight.xu@gmail.com
 *
 * Program definitions:
 */

#include "Cfg.h"
#include "MenuCall.h"
#include "LeftVboxFace.h"

void
on_quit_file_activate (GtkMenuItem	*menuitem, gpointer user_data)
{
	printf("bey world;\n");
	close_uart();
	gtk_main_quit();
}

void
on_config_activate (GtkMenuItem *menuitem, gpointer user_data)
{
	struct xcomdata *xcomdata = (struct xcomdata *)user_data;
	GtkWidget *window_cfg = create_configuration_dialog (user_data);
	
	gtk_widget_show (window_cfg);
}

void
on_ascii_talbe_activate (GtkMenuItem *menuitem, gpointer user_data)
{
	GtkWidget *window_ascii = (GtkWidget *)create_ascii_table();
	gtk_widget_show (window_ascii);
}

void
on_help_xgcom_activate (GtkMenuItem *menuitem, gpointer user_data)
{
	gchar help_msg[1024];
	
	snprintf(help_msg, 1024, 
		"<b>软件介绍</b>\n"
		"一个Linux下的图形化的串口调试工具.帮助开发者调试串口程序. \n\n"
		"<b>软件功能</b>\n"
		"1.串口基本收发\n"
		"2.串口配置(串口,速率,数据位,停止位,奇偶校验,数据控制)\n"
		"3.串口配置的保存和载入(串口,速率,数据位,停止位,奇偶校验,数据控制)\n"
		"4.串口HEX显示接收数据\n"
		"5.串口接收数据和发送数据的计数显示(按字节)\n"
		"6.串口接收数据的捕获(捕获到固定文件,但可以是追加捕获或是覆盖捕获)\n"
		"7.文件发送(选择指定文件去发送)\n"
		"8.串口HEX发送(以16进制的方式发送输入字符)\n"
		"9.连续定时间间隔发送数据,发送间隔时间可以自己设置\n"
		"10.面板托盘显示(可以隐藏或显示)\n"
		"11.终端控制功能(像minicom那样可以直接在终端输入进行相应)\n"
		"12.本地回显.");

	create_xgcom_msg ((GtkWidget *)user_data, help_msg);

}

void
on_about_xgcom_activate (GtkMenuItem *menuitem, gpointer user_data)
{
	GtkWidget *window_about;

	window_about = (GtkWidget *)create_about_xcomtool ((GtkWidget *)user_data);
	gtk_widget_show (window_about);
}
