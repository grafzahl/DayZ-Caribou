private["_seconds","_humanity","_banditKills","_humanKills","_temperature","_body","_name","_method","_methodStr"];
_body = 	_this select 3;
_name = 	_body getVariable["bodyName","unknown"];
_method = 	_body getVariable["deathType","unknown"];
_methodStr = localize format ["str_death_%1",_method];
_seconds = _body getVariable["dead_DeathTime",60];
_temperature = ceil((serverTime - _seconds)/60);
_humanKills = 	_body getVariable["dead_HumanKills",0];
_banditKills = 	_body getVariable["dead_BanditKills",0];
_humanity = 	_body getVariable["dead_Humanity",0];

playSound "beep";
hintSilent parseText format ["
<t size='1.20' font='Bitstream' align='center'>Death of %1<br/><br/></t>

<t size='1' font='Bitstream' align='left' color='#FF0000'>Survivors killed:</t><t size='1' font='Bitstream' align='right'>%2</t><br/>
<t size='1' font='Bitstream' align='left' color='#FF0000'>Bandits killed:</t><t size='1' font='Bitstream' align='right'>%3</t><br/><br/>
<t size='1' font='Bitstream' align='left' color='#FF0000'>Humanity:</t><t size='1' font='Bitstream' align='right'>%4</t><br/>
<t size='1' font='Bitstream' align='left' color='#FF0000'>Died:</t><t size='1' font='Bitstream' align='right'>%5 Minutes ago</t>
",_name,_humanKills,_banditKills,_humanity,_temperature];

//cutText [format["Name: %1 | Survivors killed: %1 | Bandits killed: ",_name,_methodStr], "PLAIN DOWN"];
