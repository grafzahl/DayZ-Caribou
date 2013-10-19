col_cold = ppEffectCreate ["colorCorrections", 1503]; 
col_cold ppEffectEnable true;
col_cold ppEffectAdjust [1.0, 1.0, 0.0,[0.2, 0.2, 1.0, 0.0],[0.4, 0.75, 1.0, 0.2],[0.5,0.3,1.0,-0.1]];
col_cold ppEffectCommit 0;
