private["_zombieKills","_daysAlive","_seconds","_humanity","_banditKills","_humanKills","_temperature","_body","_name","_method","_methodStr"];
_body = 	_this select 3;
_name = 	_body getVariable["bodyName","unknown"];
_method = 	_body getVariable["deathType","unknown"];
_methodStr = localize format ["str_death_%1",_method];
_seconds = _body getVariable["processedDeath",diag_tickTime];
_temperature = ceil((diag_tickTime - _seconds)/60);
_humanKills = 	_body getVariable["humanKills",0];
_banditKills = 	_body getVariable["banditKills",0];
_zombieKills = 	_body getVariable["zombieKills",0];
_humanity = 	_body getVariable["humanity",0];
_daysAlive = 	_body getVariable["dead_DaysAlive",0];

playSound "beep";
hintSilent parseText format ["
	<t size='1.20' font='Bitstream' align='center'>Death of: %1<br/><br/></t>

	<t size='1' font='Bitstream' align='left' color='#FF0000'>Survivors Killed:</t><t size='1' font='Bitstream' align='right'>%2</t><br/>
	<t size='1' font='Bitstream' align='left' color='#FF0000'>Bandits Killed:</t><t size='1' font='Bitstream' align='right'>%3</t><br/>
	<t size='1' font='Bitstream' align='left' color='#FF0000'>Zombies Killed:</t><t size='1' font='Bitstream' align='right'>%8</t><br/><br/>

	<t size='1' font='Bitstream' align='left' color='#FF0000'>Days Alive:</t><t size='1' font='Bitstream' align='right'>%7</t><br/>
	<t size='1' font='Bitstream' align='left' color='#FF0000'>Humanity:</t><t size='1' font='Bitstream' align='right'>%4</t><br/><br/>

	<t size='1' font='Bitstream' align='left' color='#FF0000'>Died:</t><t size='1' font='Bitstream' align='right'>%5 Minutes ago</t><br/>
	<t size='1' font='Bitstream' align='left' color='#FF0000'>Reason:</t><t size='1' font='Bitstream' align='right'>%6</t>
",_name,_humanKills,_banditKills,_humanity,_temperature,_methodStr,_daysAlive,_zombieKills];

//cutText [format["Name: %1 | Survivors killed: %1 | Bandits killed: ",_name,_methodStr], "PLAIN DOWN"];
