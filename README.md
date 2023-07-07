[ok] PlaySound - It is now able to play a sound with duration configured as zero.
[ok] AnimateCharacter - If a ModelToAnimate was not setup, It will try to get the artist by using tags "Performer" and "StageArtist". Also duration 0 is now a warning, not an error.
[ok] ChangeClocktime - Duration 0 is now a warning, not an error.
[ok] MoveArtist - Removed Duration NumberValue from the operation since it is irrelevant for the operation itself, but it was programatically added to the folder on the Setup function, since it is still needed by the Server script. Destination is now a warning.
[ok] ChangeClocktime - Slightly changed the code so when there's no DayTimeKeys configured, the code will only emit a warning.
[ok] BlinkCenterStageSpotlights- Duration 0 and StroboInterval 0 is now a warning, not an error. Also, fixed a small logic error on CheckConfigs function
[ok] ChangeAnyStageSpotlightsDirection - All the validations show warning instead of throwing error.
[ok] ChangeCenterStageSpotlightsColor - Duration 0 is now a warning, not an error.
[ok] ChangeCenterStageSpotlightsTarget - All the validations show warning instead of throwing error.
[ok] IntercalateAnySpotlightColors - All the validations show warning instead of throwing error. Added a new validation. Added OPERATION_TAG to help identify the operation with error
[] BlinkBackStageUpperSpotlights - All the validations show warning instead of throwing error.
[] ChangeBackStageUpperSpotlightsColor - Duration 0 is now a warning, not an error.
[] ChangeBackStageUpperSpotlightsTarget - All the validations show warning instead of throwing error.
[] BlinkCenterStageRoundLedColors - All the validations show warning instead of throwing error.
[] ChangeCenterStageRoundLedColors - All the validations show warning instead of throwing error.
[] IntercalateCenterStageRoundLedColors - Duration 0 and no round LEDs tags show warning instead of error
[] TurnOffCenterStageRoundLeds - Duration 0 and no round LEDs tags show warning instead of error
[] BlinkEntireStageLedColors - Duration 0 and no blink interval now shows warning instead of error
[] ChangeEntireStageLedColors - All the validations show warning instead of throwing error.
[] IntercalateEntireStageLedColors - All the validations show warning instead of throwing error.
[] TurnOffEntireStageLeds - All the validations show warning instead of throwing error.
[] BlinkFrontStageRoundLedColors - All the validations show warning instead of throwing error.
[] ChangeFrontStageRoundLedColors - All the validations show warning instead of throwing error.
[] IntercalateFrontStageRoundLedColors - All the validations show warning instead of throwing error.
[] TurnOffFrontStageRoundLeds - All the validations show warning instead of throwing error.
[] ChangeFrontStageParticleCannonsDirection - All the validations show warning instead of throwing error.
[] ChangeFrontStageParticleCannonsTarget - All the validations show warning instead of throwing error.
[] StartFrontStageParticleCannons - All the validations show warning instead of throwing error.
[] StartGroundParticleCannons - All the validations show warning instead of throwing error.
[] StartSoundBoxesParticles - All the validations show warning instead of throwing error.
[] BlinkSurroundingLedColors - All the validations show warning instead of throwing error.
[] ChangeSurroundingLedColors - All the validations show warning instead of throwing error.
[] IntercalateSurroundingLedColors - All the validations show warning instead of throwing error.
[] TurnOffSurroundingLeds - All the validations show warning instead of throwing error.