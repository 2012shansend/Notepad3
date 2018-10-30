﻿/******************************************************************************
*                                                                             *
*                                                                             *
* Notepad3                                                                    *
*                                                                             *
* Edit.h                                                                      *
*   Text File Editing Helper Stuff                                            *
*   Based on code from Notepad2, (c) Florian Balmer 1996-2011                 *
*                                                                             *
*                                                  (c) Rizonesoft 2008-2016   *
*                                                    https://rizonesoft.com   *
*                                                                             *
*                                                                             *
*******************************************************************************/
#pragma once
#ifndef _NP3_EDIT_H_
#define _NP3_EDIT_H_

#include "Scintilla.h"
#include "SciCall.h"
#include "TypeDefs.h"

void  EditInitializeSciCtrl(HWND);
void  EditInitWordDelimiter(HWND hwnd);
void  EditSetNewText(HWND hwnd,char* lpstrText,DWORD cbText);
bool  EditConvertText(HWND hwnd,int encSource,int encDest,bool);
bool  EditSetNewEncoding(HWND hwnd,int iNewEncoding,bool,bool);
bool  EditIsRecodingNeeded(WCHAR* pszText,int cchLen);
char* EditGetClipboardText(HWND hwnd,bool,int* pLineCount,int* pLenLastLn);
bool  EditSetClipboardText(HWND hwnd, const char* pszText, size_t cchText);
bool  EditClearClipboard(HWND hwnd);
bool  EditSwapClipboard(HWND hwnd,bool);
bool  EditCopyAppend(HWND hwnd,bool);
void  EditDetectEOLMode(LPCSTR lpData, DWORD cbData, EditFileIOStatus* status);
bool  EditLoadFile(HWND hwnd, LPWSTR pszFile, bool, bool, EditFileIOStatus* status);
bool  EditSaveFile(HWND hwnd,LPCWSTR pszFile, EditFileIOStatus* status, bool bSaveCopy);

void  EditInvertCase(HWND hwnd);
void  EditTitleCase(HWND hwnd);
void  EditSentenceCase(HWND hwnd);

void  EditURLEncode(HWND hwnd);
void  EditURLDecode(HWND hwnd);
void  EditEscapeCChars(HWND hwnd);
void  EditUnescapeCChars(HWND hwnd);
void  EditChar2Hex(HWND hwnd);
void  EditHex2Char(HWND hwnd);
void  EditFindMatchingBrace(HWND hwnd);
void  EditSelectToMatchingBrace(HWND hwnd);
void  EditModifyNumber(HWND hwnd,bool);

void  EditTabsToSpaces(HWND hwnd,int nTabWidth,bool);
void  EditSpacesToTabs(HWND hwnd,int nTabWidth,bool);

void  EditMoveUp(HWND hwnd);
void  EditMoveDown(HWND hwnd);
void  EditJumpToSelectionEnd(HWND hwnd);
void  EditJumpToSelectionStart(HWND hwnd);
void  EditModifyLines(HWND hwnd,LPCWSTR pwszPrefix,LPCWSTR pwszAppend);
void  EditIndentBlock(HWND hwnd,int cmd,bool);
void  EditAlignText(HWND hwnd,int nMode);
void  EditEncloseSelection(HWND hwnd,LPCWSTR pwszOpen,LPCWSTR pwszClose);
void  EditToggleLineComments(HWND hwnd,LPCWSTR pwszComment,bool);
void  EditPadWithSpaces(HWND hwnd,bool,bool);
void  EditStripFirstCharacter(HWND hwnd);
void  EditStripLastCharacter(HWND hwnd,bool,bool);
void  EditCompressBlanks(HWND hwnd);
void  EditRemoveBlankLines(HWND hwnd,bool,bool);
void  EditRemoveDuplicateLines(HWND hwnd,bool);
void  EditWrapToColumn(HWND hwnd,DocPos nColumn);
void  EditSplitLines(HWND hwnd);
void  EditJoinLinesEx(HWND hwnd,bool,bool);
void  EditSortLines(HWND hwnd,int iSortFlags);

void  EditJumpTo(HWND hwnd, DocLn iNewLine, DocPos iNewCol);
void  EditScrollTo(HWND hwnd, DocLn iScrollToLine, int iSlop);
void  EditSetSelectionEx(HWND hwnd, DocPos iAnchorPos, DocPos iCurrentPos, DocPos vSpcAnchor, DocPos vSpcCurrent);
void  EditFixPositions(HWND hwnd);
void  EditEnsureSelectionVisible(HWND hwnd);
void	EditEnsureConsistentLineEndings(HWND hwnd);
void  EditGetExcerpt(HWND hwnd,LPWSTR lpszExcerpt,DWORD cchExcerpt);

HWND  EditFindReplaceDlg(HWND hwnd,LPCEDITFINDREPLACE lpefr,bool);
bool  EditFindNext(HWND hwnd,LPCEDITFINDREPLACE lpefr,bool,bool);
bool  EditFindPrev(HWND hwnd,LPCEDITFINDREPLACE lpefr,bool,bool);
bool  EditReplace(HWND hwnd,LPCEDITFINDREPLACE lpefr);
int   EditReplaceAllInRange(HWND hwnd,LPCEDITFINDREPLACE lpefr,DocPos iStartPos,DocPos iEndPos,DocPos* enlargement);
bool  EditReplaceAll(HWND hwnd,LPCEDITFINDREPLACE lpefr,bool);
bool  EditReplaceAllInSelection(HWND hwnd,LPCEDITFINDREPLACE lpefr,bool);
bool  EditLinenumDlg(HWND hwnd);
bool  EditModifyLinesDlg(HWND hwnd,LPWSTR pwsz1,LPWSTR pwsz2);
bool  EditEncloseSelectionDlg(HWND hwnd,LPWSTR pwszOpen,LPWSTR pwszClose);
bool  EditInsertTagDlg(HWND hwnd,LPWSTR pwszOpen,LPWSTR pwszClose);
bool  EditSortDlg(HWND hwnd,int* piSortFlags);
bool  EditAlignDlg(HWND hwnd,int* piAlignMode);
bool  EditPrint(HWND,LPCWSTR,LPCWSTR);
void  EditPrintSetup(HWND);
void  EditPrintInit();
void  EditMatchBrace(HWND hwnd);
void  EditClearAllOccurrenceMarkers(HWND hwnd);
bool  EditToggleView(HWND hwnd, bool bToggleView);
void  EditMarkAll(HWND hwnd, char* pszFind, int flags, DocPos rangeStart, DocPos rangeEnd, bool, bool);
void  EditUpdateUrlHotspots(HWND hwnd, DocPos startPos, DocPos endPos, bool);
void  EditSetAccelWordNav(HWND hwnd,bool);
bool  EditAutoCompleteWord(HWND hwnd,bool);
void  EditGetBookmarkList(HWND hwnd,LPWSTR pszBookMarks,int cchLength);
void  EditSetBookmarkList(HWND hwnd,LPCWSTR pszBookMarks);
void  EditFinalizeStyling(HWND hwnd, DocPos iEndPos);

void  EditMarkAllOccurrences(HWND hwnd, bool bForceClear);
void  EditUpdateVisibleUrlHotspot(bool);
void  EditHideNotMarkedLineRange(HWND hwnd, DocPos iStartPos, DocPos iEndPos, bool);

//  if iRangeEnd == -1 : apply style from iRangeStart to document end
inline void EditApplyLexerStyle(HWND hwnd, const DocPos iRangeStart, const DocPos iRangeEnd) {
  (void)(hwnd); SciCall_Colourise(iRangeStart, iRangeEnd);
}


#define FV_TABWIDTH        1
#define FV_INDENTWIDTH     2
#define FV_TABSASSPACES    4
#define FV_TABINDENTS      8
#define FV_WORDWRAP       16
#define FV_LONGLINESLIMIT 32
#define FV_ENCODING       64
#define FV_MODE          128

typedef struct _filevars {

  int mask;
  int iTabWidth;
  int iIndentWidth;
  bool bTabsAsSpaces;
  bool bTabIndents;
  bool fWordWrap;
  int iLongLinesLimit;
  char tchEncoding[32];
  int  iEncoding;
  char tchMode[32];

} FILEVARS, *LPFILEVARS;

bool FileVars_Init(char* lpData,DWORD cbData,LPFILEVARS lpfv);
bool FileVars_Apply(HWND hwnd,LPFILEVARS lpfv);
bool FileVars_ParseInt(char* pszData,char* pszName,int* piValue);
bool FileVars_ParseStr(char* pszData,char* pszName,char* pszValue,int cchValue);
bool FileVars_IsUTF8(LPFILEVARS lpfv);
bool FileVars_IsNonUTF8(LPFILEVARS lpfv);
bool FileVars_IsValidEncoding(LPFILEVARS lpfv);
int  FileVars_GetEncoding(LPFILEVARS lpfv);


//
//  Folding Functions
//
typedef enum {
  FOLD = SC_FOLDACTION_CONTRACT,
  EXPAND = SC_FOLDACTION_EXPAND,
  SNIFF = SC_FOLDACTION_TOGGLE
} FOLD_ACTION;

typedef enum {
  UP = -1,
  NONE = 0,
  DOWN = 1
} FOLD_MOVE;

void EditToggleFolds(FOLD_ACTION action,bool);
void EditFoldClick(DocLn ln, int mode);
void EditFoldAltArrow(FOLD_MOVE move, FOLD_ACTION action);

void EditShowZoomCallTip(HWND hwnd);
void EditShowZeroLengthCallTip(HWND hwnd, DocPos iPosition);

#define NP3_BRACES_TO_MATCH "()[]{}"

#endif //_NP3_EDIT_H_

///   End of Edit.h   ///
