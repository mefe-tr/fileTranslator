#!/usr/bin/env python3
# -*- coding: Latin 1 -*-

def getSupportedLanguages(s) :
    try:
        from deep_translator import GoogleTranslator

        langsList = GoogleTranslator.get_supported_languages()
        langsList = [lang.title() for lang in langsList]

        listToStr = ','.join(map(str, langsList))
        return listToStr
    except :
        return "ERROR"

def translateDeepTranslator_text(fileName="", srcLang="chinese (simplified)", destLang="english"): # I prefer to use this function because it is quite simple and fast
# -*- coding: Latin 1 -*-
    from deep_translator import GoogleTranslator
    import os
    import chardet

    try:
        if not(os.path.isfile(fileName)) : # is it a proper filename?
            return "ERROR1"

        partCount = 0
        head, tail = os.path.split(fileName)
        outputFileName = head + "\\_" + tail #output translated file name
        tempFileName = head + "\\__" + tail  # temporary file

        if os.path.isfile(outputFileName) : # if output file is exists, it will be deleted firstly
            os.remove(outputFileName)

        charenc = 'utf-8'
        with open(fileName, mode='rb') as f: # detect comment file's encoding name
            rawdata = f.read()
            result = chardet.detect(rawdata)
            charenc = result['encoding']
            del f
            del rawdata
            del result
        
        restOfText = ""
        with open(fileName, mode='r', encoding=charenc, errors='ignore' ) as f : #comment file is converted to utf-8 encoding file
            fileSize = os.path.getsize(fileName)
            readSize = 4999  # permitted maximum file size to translate is 5000 characters.

            while fileSize > 0 : # that's why if the file size that will be translated is larger than 5000 characters, the file will be split parts of 5000 characters
                s = f.read( readSize )
                s = s.encode('utf8', 'ignore').decode('utf8')

                s = restOfText + s # add half text 

                lastLinePos = len(s)-1 #default last index
                if len(s) >= 4999 :
                    lastLinePos = s.rfind("\n") # Find last line position. We don't want to get half of a line
                    restOfText = s[lastLinePos:] # get 

                else:
                    restOfText = ""

                tempFileName = head + "\\"+str(partCount)+"_" + tail
                open(tempFileName, mode='w', encoding='utf8').write(s[:lastLinePos])

                partCount = partCount + 1

                fileSize = fileSize - readSize
                if fileSize > 4999 :
                    readSize = 4999
                else:
                    readSize = fileSize

                del s

            del f

        if restOfText != "" : # if we have rest of text, we added it a last file
            tempFileName = head + "\\"+str(partCount)+"_" + tail
            open(tempFileName, mode='w', encoding='utf8').write(restOfText)
            partCount = partCount + 1

        for index in range(partCount): # Files split into 5000-character chunks will be read and translated sequentially

            tempFileName = head + "\\"+str(index)+"_" + tail
            translated = GoogleTranslator(source=srcLang.lower(), target=destLang.lower()).translate_file(tempFileName)
            os.remove(tempFileName)

            with open(outputFileName, 'a') as f: # translated text will be written into output file.
                if index != 0 : f.write( '\n' )
                f.write( translated )
                del f

            del translated     

        return "OK"
    except Exception as ex:
        return "ERROR2" + ex.args[0]

