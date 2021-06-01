/**
 * Copyright (c) 2021 OceanBase
 * OceanBase CE is licensed under Mulan PubL v2.
 * You can use this software according to the terms and conditions of the Mulan PubL v2.
 * You may obtain a copy of Mulan PubL v2 at:
 *          http://license.coscl.org.cn/MulanPubL-2.0
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PubL v2 for more details.
 */

#ifndef OCEANBASE_TRANSACTION_OB_TRANS_MSG_TYPE_
#define OCEANBASE_TRANSACTION_OB_TRANS_MSG_TYPE_

namespace oceanbase {
namespace transaction {

enum ObTransMsgType {
  OB_TRANS_MSG_UNKNOWN = -1,

  OB_TRANS_COMMIT_REQUEST = 0,
  OB_TRANS_COMMIT_RESPONSE = 1,
  OB_TRANS_ABORT_REQUEST = 2,
  OB_TRANS_ABORT_RESPONSE = 3,

  OB_TRANS_STMT_CREATE_CTX_REQUEST = 4,
  OB_TRANS_STMT_CREATE_CTX_RESPONSE = 5,
  OB_TRANS_STMT_ROLLBACK_REQUEST = 6,
  OB_TRANS_STMT_ROLLBACK_RESPONSE = 7,
  OB_TRANS_CLEAR_REQUEST = 8,
  OB_TRANS_CLEAR_RESPONSE = 9,
  OB_TRANS_START_STMT_REQUEST = 10,
  OB_TRANS_START_STMT_RESPONSE = 11,
  OB_TRANS_DISCARD_REQUEST = 12,
  OB_TRANS_ASK_SCHEDULER_STATUS_REQUEST = 13,
  OB_TRANS_ASK_SCHEDULER_STATUS_RESPONSE = 14,
  OB_TRANS_SAVEPOINT_ROLLBACK_REQUEST = 15,
  OB_TRANS_SAVEPOINT_ROLLBACK_RESPONSE = 16,

  OB_TRANS_2PC_LOG_ID_REQUEST = 96,
  OB_TRANS_2PC_LOG_ID_RESPONSE = 97,
  OB_TRANS_2PC_PRE_PREPARE_REQUEST = 98,
  OB_TRANS_2PC_PRE_PREPARE_RESPONSE = 99,
  OB_TRANS_2PC_PREPARE_REQUEST = 100,
  OB_TRANS_2PC_PREPARE_RESPONSE = 101,
  OB_TRANS_2PC_COMMIT_REQUEST = 102,
  OB_TRANS_2PC_COMMIT_RESPONSE = 103,
  OB_TRANS_2PC_ABORT_REQUEST = 104,
  OB_TRANS_2PC_ABORT_RESPONSE = 105,
  OB_TRANS_2PC_CLEAR_REQUEST = 106,
  OB_TRANS_2PC_CLEAR_RESPONSE = 107,
  OB_TRANS_2PC_COMMIT_CLEAR_REQUEST = 108,
  OB_TRANS_2PC_COMMIT_CLEAR_RESPONSE = 109,
  OB_TRANS_2PC_PRE_COMMIT_REQUEST = 110,
  OB_TRANS_2PC_PRE_COMMIT_RESPONSE = 111,

  OB_TRANS_SP_REQUEST = 201,
  OB_TRANS_SP_RESPONSE = 202,

  OB_TRANS_XA_PREPARE_REQUEST = 211,
  OB_TRANS_XA_PREPARE_RESPONSE = 212,
  OB_TRANS_XA_COMMIT_REQUEST = 213,
  OB_TRANS_XA_ROLLBACK_REQUEST = 214,
  OB_TRANS_XA_ROLLBACK_RESPONSE = 215,
  OB_TRANS_XA_SYNC_STATUS = 216,
  OB_TRANS_XA_SYNC_STATUS_RESPONSE = 217,
  OB_TRANS_XA_MERGE_STATUS = 218,

  OB_TRANS_ERROR_MSG = 301
};

const int32_t OB_TRX_NEW_MSG_TYPE_BASE = 1000;

class ObTransMsgTypeChecker {
  public:
  static bool is_valid_msg_type(const int64_t msg_type)
  {
    return ((0 <= msg_type && 16 >= msg_type) || (96 <= msg_type && 111 >= msg_type) ||
            (201 <= msg_type && 202 >= msg_type) || (211 <= msg_type && 215 >= msg_type) || 301 == msg_type);
  }
  static bool is_request(const int64_t msg_type)
  {
    return OB_TRANS_COMMIT_REQUEST == msg_type || OB_TRANS_XA_PREPARE_REQUEST == msg_type ||
           OB_TRANS_XA_COMMIT_REQUEST == msg_type || OB_TRANS_ABORT_REQUEST == msg_type ||
           OB_TRANS_XA_ROLLBACK_REQUEST == msg_type || OB_TRANS_STMT_CREATE_CTX_REQUEST == msg_type ||
           OB_TRANS_STMT_ROLLBACK_REQUEST == msg_type || OB_TRANS_CLEAR_REQUEST == msg_type ||
           OB_TRANS_START_STMT_REQUEST == msg_type || OB_TRANS_DISCARD_REQUEST == msg_type ||
           OB_TRANS_ASK_SCHEDULER_STATUS_REQUEST == msg_type || OB_TRANS_2PC_LOG_ID_REQUEST == msg_type ||
           OB_TRANS_2PC_PRE_PREPARE_REQUEST == msg_type || OB_TRANS_2PC_PREPARE_REQUEST == msg_type ||
           OB_TRANS_2PC_COMMIT_REQUEST == msg_type || OB_TRANS_2PC_ABORT_REQUEST == msg_type ||
           OB_TRANS_2PC_CLEAR_REQUEST == msg_type || OB_TRANS_2PC_COMMIT_CLEAR_REQUEST == msg_type ||
           OB_TRANS_2PC_PRE_COMMIT_REQUEST == msg_type || OB_TRANS_SP_REQUEST == msg_type ||
           OB_TRANS_SAVEPOINT_ROLLBACK_REQUEST == msg_type;
  }
  static bool is_2pc_msg_type(const int64_t msg_type)
  {
    return (msg_type >= OB_TRANS_2PC_LOG_ID_REQUEST && msg_type <= OB_TRANS_2PC_PRE_COMMIT_RESPONSE);
  }

  private:
  ObTransMsgTypeChecker()
  {}
  ~ObTransMsgTypeChecker()
  {}
};

}  // namespace transaction
}  // namespace oceanbase

#endif  // OCEANBASE_TRANSACTION_OB_TRANS_MSG_TYPE_