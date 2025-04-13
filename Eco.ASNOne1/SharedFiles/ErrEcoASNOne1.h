/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   ErrEcoASNOne1
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

#ifndef __ERR_ECO_ASN_ONE_1_H__
#define __ERR_ECO_ASN_ONE_1_H__


/*
 * <код ошибки>
 *   ERR_ECO_ASN1_REQ_COMP_LIST
 * </код ошибки>
 *
 * <описание>
 *   Требуется компонент для работы со списком IEcoList1
 * </описание>
 *
 * <CID>
 *   CID_EcoList1 = {53884AFC-93C4-48EC-AA92-9C8D3A562281}
 * </CID>
 */
#define ERR_ECO_ASN1_REQ_COMP_LIST 1001


/*
 * <код ошибки>
 *   ERR_ECO_ASN1_INVALID_SIZE
 * </код ошибки>
 *
 * <описание>
 *   Недопустимый размер значения
 * </описание>
 *
 */
#define ERR_ECO_ASN1_INVALID_SIZE 2001


/*
 * <код ошибки>
 *   ERR_ECO_ASN1_INVALID_VALUE
 * </код ошибки>
 *
 * <описание>
 *   Значение не установлено
 * </описание>
 *
 */
#define ERR_ECO_ASN1_INVALID_VALUE 2002

/*
 * <код ошибки>
 *   ERR_ECO_ASN1_INVALID_TYPE
 * </код ошибки>
 *
 * <описание>
 *   ASN.1 тип не установлен
 * </описание>
 *
 */
#define ERR_ECO_ASN1_INVALID_TYPE 2003

#endif /* __ERR_ECO_ASN_ONE_1_H__ */
