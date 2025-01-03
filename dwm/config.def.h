/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
/* static const char col_cyan[]        = "#d09000"; */
static const char col_cyan[]        = "#005577";
/* static const char col_cyan[]        = "#283c56"; */
/* static const char col_cyan[]        = "#0E4C92"; */
/* static const char col_cyan[]        = "#ffbf00"; */
/* static const char col_cyan[]        = "#d19f08"; */
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };




static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                 instance    title       tags mask     isfloating   monitor   scratch key */
	{ "Gimp",                NULL,       NULL,       1 << 0,       0,           0,        0 },
	{ "Firefox",             NULL,       NULL,       1 << 0,       0,           0,        0 },
	{ "Signal",              NULL,       NULL,       1 << 0,       0,           2,        0 },
	{ "discord",             NULL,       NULL,       1 << 0,       0,           2,        0 },
	{ "nheko",               NULL,       NULL,       1 << 0,       0,           2,        0 },
	{ "ArmCord",             NULL,       NULL,       1 << 0,       0,           2,        0 },
	{ "WebApp-Discord0838",  NULL,       NULL,       1 << 0,       0,           2,        0 },
	{ "iamb",                NULL,       NULL,       1 << 0,       0,           2,        0 },
	{ "SchildiChat",         NULL,       NULL,       1 << 0,       0,           2,        0 },
	{ "steam",               NULL,       NULL,       1 << 3,       0,           2,        0 },
	{ "steamwebhelper",      NULL,       NULL,       1 << 3,       0,           2,        0 },
	{ "steam_app_",  "steam_app_",       NULL,       1 << 3,       0,           0,        0 },
	{ "PrismLauncher",       NULL,       NULL,       1 << 4,       0,           2,        0 },
	{ "obsidian",            NULL,       NULL,       0,            1,          -1,       'o'},
	{ "Geary",               NULL,       NULL,       1 << 2,       0,           2,        0 },
	{ "virt-viewer",         NULL,       NULL,       1 << 3,       0,           0,        0 }, 
	{ "Spotify",             NULL,       NULL,       0,            1,          -1,       's'},
	{ "electron-mail",       NULL,       NULL,       1 << 2,       0,           2,        0 },
	{ "qBittorrent",         NULL,       NULL,       1 << 5,       0,           2,        0 },
	{ "Nextcloud",           NULL,       NULL,       1 << 8,       0,           1,        0 },
	{ "nextcloud",           NULL,       NULL,       1 << 8,       0,           1,        0 },
	{ "eadesktop.exe",       NULL,       NULL,       1 << 4,       0,           2,        0 },
  /* Backup if scratchpads does not work for me */
//	{ "Spotify",             NULL,       NULL,       1 << 1,     0,          0,           2,        0 },
//	{ "obsidian",            NULL,       NULL,       1 << 4,     0,          0,           2,        0 },
};

static const MonitorRule monrules[] = {
	/* monitor layout  mfact  nmaster  showbar  topbar */
	//{  2,      0,      -1,     0,      -1,      -1     }, // use a different layout for the second monitor
	{  1,      0,      -1,     0,       0,      -1     }, // use a different layout for the second monitor
	{ -1,      0,      -1,    -1,       0,      -1     }, // default
};

/* layout(s) */
static const float mfact     = 0.56; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
/* static const char *dmenucmd[] = { "rofi", "-show", "run", NULL }; */
/* static const char *termcmd[]  = { "alacritty", "-o", "font.size=15", NULL }; */
static const char *termcmd[]  = { "kitty",  NULL }; 


/* First arg only serves to match against key in rules*/
static const char *spotify[] = {"s", "spotify", NULL};
static const char *obsidian[] = {"o", "obsidian", NULL};


#include "movestack.c"
static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_g,      togglescratch,  {.v = spotify } },
	{ MODKEY|ShiftMask,             XK_g,      removescratch,  {.v = spotify } },
	{ MODKEY|ControlMask,           XK_g,      setscratch,     {.v = spotify } },
	{ MODKEY,                       XK_r,      togglescratch,  {.v = obsidian } },
	{ MODKEY|ShiftMask,             XK_r,      removescratch,  {.v = obsidian } },
	{ MODKEY|ControlMask,           XK_r,      setscratch,     {.v = obsidian } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_v,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_z,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_u,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = -1 } },
	{ MODKEY|ControlMask|ShiftMask, XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY|ControlMask|ShiftMask, XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_s,      zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_h,      focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_l,      focusmon,       {.i = +1 } },
	{ MODKEY,                       XK_x,      focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_c,      focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_h,      tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_l,      tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_a,      tagmon,         {.i = +1 } },
	{ MODKEY|ControlMask,           XK_l,      tagswapmon,     {.i = +1 } },
	{ MODKEY|ControlMask,           XK_h,      tagswapmon,     {.i = -1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_e,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	/* placemouse options, choose which feels more natural:
	 *    0 - tiled position is relative to mouse cursor
	 *    1 - tiled postiion is relative to window center
	 *    2 - mouse pointer warps to window center
	 *
	 * The moveorplace uses movemouse or placemouse depending on the floating state
	 * of the selected client. Set up individual keybindings for the two if you want
	 * to control these separately (i.e. to retain the feature to move a tiled window
	 * into a floating position).
	 */
	{ ClkClientWin,         MODKEY,         Button1,        moveorplace,    {.i = 1} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

