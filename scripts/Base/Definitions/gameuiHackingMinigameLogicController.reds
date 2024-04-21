public native class gameuiHackingMinigameLogicController extends inkLogicController {
  native let grid: inkUniformGridRef;
  native let buffer: inkCompoundRef;
  native let programs: inkCompoundRef;
  native let timer: inkTextRef;
  native let timerProgressBar: inkWidgetRef;
  native let timerContainer: inkWidgetRef;
  native let timerPlaceholder: inkWidgetRef;
  native let accessInformationText: inkTextRef;
  native let activatedTraps: inkCompoundRef;
  native let gridVerticalHiglight: inkWidgetRef;
  native let gridHorizontalHiglight: inkWidgetRef;
  native let programsColumnHiglight: inkWidgetRef;
  native let successScreenWidget: inkCompoundRef;
  native let failScreenWidget: inkCompoundRef;
  native let successExitTerminalText: inkTextRef;
  native let failedExitTerminalText: inkTextRef;
  native let successExitButton: inkWidgetRef;
  native let failureExitButton: inkWidgetRef;
  native let resetButton: inkWidgetRef;
  native let introAnimName: CName;
  native let loopAnimName: CName;
  native let cursorAnimName: CName;
  native let higlightAnimName: CName;
  native let gameWonAnimName: CName;
  native let gameLostAnimName: CName;
  native let terminalShutdownAnimName: CName;
  native let trapActivatedAnimName: CName;
  native let programSucceedAnimName: CName;
  native let programFailedAnimName: CName;
  native let programResetFromFailedAnimName: CName;
  native let gridCellHoverAnimName: CName;
  native let gridCellClickFlashAnimName: CName;
  native let bufferCellHoverAnimName: CName;
  native let bufferCellClickFlashAnimName: CName;
  native let programCellClickFlashAnimName: CName;
  native let activatedTrapIconLibraryName: CName;
  native let bufferCellLibraryName: CName;
  native let programCellLibraryName: CName;
  native let gridCellLibraryName: CName;
  native let programEntryLibraryName: CName;
  native let trapIconsContainerRelativePath: CName;
  native let bufferCellTextWidgetRelativePath: CName;
  native let programCellTextWidgetRelativePath: CName;
  native let gridCellTrapIconWidgetRelativePath: CName;
  native let gridCellTrapIconContainerRelativePath: CName;
  native let gridCellTextWidgetRelativePath: CName;
  native let gridCellProgramHighlightRelativePath: CName;
  native let programEntryTextWidgetRelativePath: CName;
  native let programEntryNoteWidgetRelativePath: CName;
  native let programEntryInstructionContainerRelativePath: CName;
  native let programEntryIconPath: CName;
  native let cursorWidgetRelativePath: CName;
  native let gridCellDefaultStateName: CName;
  native let gridCellHoveredStateName: CName;
  native let gridCellSelectedStateName: CName;
  native let gridCellDisabledStateName: CName;
  native let programSucceedStateName: CName;
  native let programFailedStateName: CName;
  native let programCellReadyStateName: CName;
  native let programCellHighlightStateName: CName;
  native let mainHiglightBarStateName: CName;
  native let secondaryHiglightBarStateName: CName;
  native let inactiveHiglightBarStateName: CName;
  native let gridCellDisabledSymbol: String;
}
