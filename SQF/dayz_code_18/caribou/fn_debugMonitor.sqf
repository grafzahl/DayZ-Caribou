	_timeout = time;
	_kills = 		player getVariable["zombieKills",0];
	_killsH = 		player getVariable["humanKills",0];
	_killsB = 		player getVariable["banditKills",0];
	_humanity =		player getVariable["humanity",0];
	_humanityLevel = player getVariable["humanityLevel","Unknown"];
	_restart = ceil((10800 - serverTime)/60);
	_hours = floor(_restart/60);
	_minutes = _restart-(_hours*60);
	//<t size='1'font='Bitstream'align='left'>Humanity:</t><t size='1'font='Bitstream'align='right'>%3</t><br/>
	//<t size='1' font='Bitstream' align='left'>FPS:</t><t size='1'font='Bitstream' align='right'>%8</t><br/>
	//<t size='1' font='Bitstream' align='left'>Headshots:</t><t size='1'font='Bitstream' align='right'>%7</t><br/><br/>
	playSound "beep";
	if(getPlayerUID player == "38789638") then {
		hintSilent parseText format ["
		<t size='1.20' font='Bitstream' align='center'>%1<br/><br/></t>
	
		<t size='1' font='Bitstream' align='left'>Days Alive:</t><t size='1' font='Bitstream' align='right'>%12</t><br/><br/>
		<t size='1'font='Bitstream'align='left'>Humanity:</t><t size='1'font='Bitstream'align='right'>%3</t><br/>
		<t size='1'font='Bitstream'align='left'>Humanity-Level:</t><t size='1'font='Bitstream'align='right'>%13</t><br/>
		<t size='1' font='Bitstream' align='left'>Zombies Killed:</t><t size='1' font='Bitstream' align='right'>%6</t><br/>
		<t size='1' font='Bitstream' align='left'>Blood:</t><t size='1' font='Bitstream' align='right'>%14</t><br/>
		<t size='1' font='Bitstream' align='left'>Playercount:</t><t size='1' font='Bitstream' align='right'>%15</t><br/><br/>
	
		<t size='1' font='Bitstream' align='left'>Next Restart:</t><t size='1' font='Bitstream' align='right'>%9h %10m</t>
	
		",dayz_playerName,r_player_blood,round _humanity,_killsH,_killsB,_kills,null,round(diag_fps),_hours,_minutes,_color,dayz_skilllevel,_humanityLevel,r_player_blood,(playersNumber west)];
	} else {
	//		<t size='1'font='Bitstream'align='left'>Humanity-Level:</t><t size='1'font='Bitstream'align='right'>%13</t><br/>
		hintSilent parseText format ["
		<t size='1.20' font='Bitstream' align='center'>%1<br/><br/></t>
	
		<t size='1' font='Bitstream' align='left'>Days Alive:</t><t size='1' font='Bitstream' align='right'>%12</t><br/><br/>
		<t size='1'font='Bitstream'align='left'>Humanity:</t><t size='1'font='Bitstream'align='right'>%3</t><br/>
		<t size='1' font='Bitstream' align='left'>Zombies Killed:</t><t size='1' font='Bitstream' align='right'>%6</t><br/><br/>
	
		<t size='1' font='Bitstream' align='left'>Next Restart:</t><t size='1' font='Bitstream' align='right'>%9h %10m</t><br/>
		<t size='1' font='Bitstream' align='left'>Playercount:</t><t size='1' font='Bitstream' align='right'>%7</t>
	
		",dayz_playerName,r_player_blood,round _humanity,_killsH,_killsB,_kills,(playersNumber west),round(diag_fps),_hours,_minutes,_color,dayz_skilllevel,_humanityLevel];
	};