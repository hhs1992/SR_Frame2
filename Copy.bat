// ��ɾ�			�ɼ�			������ ������ �ִ� ���		������ ������ ������ ���

xcopy			/y			.\Engine\Headers\*.h					.\Reference\Headers\
xcopy			/y			.\Engine\Headers\*.inl					.\Reference\Headers\

xcopy			/y			.\Engine\System\Codes\*.h				.\Reference\Headers\
xcopy			/y			.\Engine\System\Bin\System.dll			.\Client\Bin\
xcopy			/y			.\Engine\System\Bin\System.lib			.\Reference\Libraries\

xcopy			/y			.\Engine\Utility\Codes\*.h				.\Reference\Headers\
xcopy			/y			.\Engine\Utility\Bin\Utility.dll		.\Client\Bin\
xcopy			/y			.\Engine\Utility\Bin\Utility.lib		.\Reference\Libraries\

xcopy			/y			.\Engine\Resources\Codes\*.h			.\Reference\Headers\
xcopy			/y			.\Engine\Resources\Bin\Resources.dll	.\Client\Bin\
xcopy			/y			.\Engine\Resources\Bin\Resources.lib	.\Reference\Libraries\