/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   ErrEcoVFB1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает коды ошибок
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __ERR_ECO_VFB_1_H__
#define __ERR_ECO_VFB_1_H__

#define ECO_VFB_OK                                  ERR_ECO_OK
#define ECO_VFB_EXIT                                ERR_ECO_USER+0x0001
#define ECO_VFB_INVALID_WINDOW                      ERR_ECO_USER+0x0002
#define ECO_VFB_INVALID_BUFFER                      ERR_ECO_USER+0x0003
#define ECO_VFB_INTERNAL_ERROR                      ERR_ECO_USER+0x0004
#define ECO_VFB_NOSUPPORT                           ERR_ECO_USER+0x0005

/*
 * <код ошибки>
 *   ERR_ECO_VFB_REQ_COMP_IPCC_MAILBOX
 * </код ошибки>
 *
 * <описание>
 *   Требуется компонент Eco.IPCC.Mailbox1 для работы с прошивкой
 * </описание>
 *
 * <CID>
 *   CID_EcoIPCCMailbox1 = {F10BC39A-4F21-43CF-8A1E-104650A2C302}
 * </CID>
 */
#define ERR_ECO_VFB_REQ_COMP_IPCC_MAILBOX           1001


#endif /* __ERR_ECO_VFB_1_H__ */
