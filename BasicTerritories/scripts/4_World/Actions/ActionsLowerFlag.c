modded class ActionLowerFlag: ActionContinuousBase
{		
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		
		if (super.ActionCondition(player, target, item)){
			TerritoryFlag theFlag = TerritoryFlag.Cast( target.GetObject() );
			PlayerBase thePlayer = PlayerBase.Cast(player);
			if ( theFlag && thePlayer && thePlayer.GetIdentity() ){
				theFlag.SyncTerritoryRateLimited();
				if (vector.Distance(theFlag.GetPosition(), thePlayer.GetPosition()) > UAMisc.MAX_DISTANCE_FROM_FLAG){
					return false;
				}
				if (!theFlag.CheckPlayerPermission(thePlayer.GetIdentity().GetId(), TerritoryPerm.LOWERFLAG)){
					GetBasicTerritoriesConfig().SendNotification(GetBasicTerritoriesConfig().LowerFlagWarningMessage, TerritoryIcons.LowerFlagWarning);
					return false;
				}
				return true;
			}
		}
		return false;
	}
	
};