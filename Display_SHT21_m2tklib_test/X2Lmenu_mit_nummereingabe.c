

//=================================================
// Forward declaration of the toplevel element
M2_EXTERN_ALIGN(top_el_x2l_menu);


//=================================================
// Define three user menus, just for demonstration.

M2_ROOT(el_mnu1_sel, "t1", "Menu 1 selected", &top_el_x2l_menu);
M2_ALIGN(top_el_mnu1_sel, "-1|1W64H64", &el_mnu1_sel);

M2_ROOT(el_mnu2_sel, "t1", "Menu 2 selected", &top_el_x2l_menu);
M2_ALIGN(top_el_mnu2_sel, "-1|1W64H64", &el_mnu2_sel);

M2_ROOT(el_mnu3_sel, "t1", "Menu 3 selected", &top_el_x2l_menu);
M2_ALIGN(top_el_mnu3_sel, "-1|1W64H64", &el_mnu3_sel);


//=================================================
uint8_t value = 0;
char buf[20];

// define callback procedure, which returns a menu entry with a value
const char *xmenu_value(uint8_t idx, uint8_t msg)
{
  if ( msg == M2_STRLIST_MSG_GET_STR ) {
    strcpy(buf, " Value: ");
    itoa((int)value, buf+strlen(buf), 10);
    return buf;
  }
  return "";
}

// define callback procedures which increment and decrement a value
const char *xmenu_inc(uint8_t idx, uint8_t msg) {
  if ( msg == M2_STRLIST_MSG_SELECT  ) {
      value++;
  }
  return "";
}

const char *xmenu_dec(uint8_t idx, uint8_t msg) {
  if ( msg == M2_STRLIST_MSG_SELECT  ) {
      value--;
  }
  return "";
}


/*=== number entry ===*/

uint8_t u8num = 0;
uint32_t u32num = 0;

void fn_num_zero(m2_el_fnarg_p fnarg) {
  u8num = 0;
  u32num = 0;
}

M2_LABEL(el_num_label1, NULL, "U8:");
M2_U8NUM(el_num_1, NULL, 0, 255, &u8num);	//das wollen wir!!

M2_LABEL(el_num_label2, NULL, "U32:");
M2_U32NUM(el_num_2, "c5", &u32num);

M2_BUTTON(el_num_zero, "f4", " zero ", fn_num_zero);
M2_ROOT(el_num_goto_top, "f4", " back ", &top_el_x2l_menu);

M2_LIST(num_list) = {
    &el_num_label1, &el_num_1,
    &el_num_label2, &el_num_2,
    &el_num_zero, &el_num_goto_top
};
M2_GRIDLIST(el_num_menu_grid, "c2", num_list);
M2_ALIGN(el_top_num_menu, "-1|1W64H64", &el_num_menu_grid);



//=================================================
// this is the overall menu structure for the X2L Menu

m2_xmenu_entry xmenu_data[] =
{
  { "Menu 1", NULL, NULL },		/* expandable main menu entry */
  { ".", NULL, xmenu_value },		/* The label of this menu line is returned by the callback procedure */
  { ". Inc", NULL, xmenu_inc },		/* This callback increments the value */
  { ". Dec", NULL, xmenu_dec },		/* This callback decrements the value */
  { "Numbers ", &el_top_num_menu },
  { "Menu 2", NULL, NULL },
  { ". Sub 2-1", &top_el_mnu1_sel, NULL },
  { ". Sub 2-2", &top_el_mnu2_sel, NULL},
  { ". Sub 2-3", &top_el_mnu3_sel, NULL },
  { NULL, NULL, NULL },
};

//=================================================
// This is the main menu dialog box

// The first visible line and the total number of visible lines.
// Both values are written by M2_X2LMENU and read by M2_VSB
uint8_t el_x2l_first = 0;
uint8_t el_x2l_cnt = 3;

// M2_X2LMENU definition
// Option l4 = four visible lines
// Option e15 = first column has a width of 15 pixel
// Option W43 = second column has a width of 43/64 of the display width
// Option F3 = select font 3 for the extra column (icons)

M2_X2LMENU(el_x2l_strlist, "l4e15W43F3", &el_x2l_first, &el_x2l_cnt, xmenu_data, 65,102,'\0');
M2_SPACE(el_x2l_space, "W1h1");
M2_VSB(el_x2l_vsb, "l4W2r1", &el_x2l_first, &el_x2l_cnt);
M2_LIST(list_x2l) = { &el_x2l_strlist, &el_x2l_space, &el_x2l_vsb };
M2_HLIST(el_x2l_hlist, NULL, list_x2l);
M2_ALIGN(top_el_x2l_menu, "-1|1W64H64", &el_x2l_hlist);


//=================================================
// m2 object and constructor
M2tk m2(&top_el_x2l_menu, m2_es_arduino, m2_eh_4bs, m2_gh_u8g_ffs);

//=================================================
// Draw procedure, Arduino Setup & Loop


void draw(void) {
  m2.draw();
}

