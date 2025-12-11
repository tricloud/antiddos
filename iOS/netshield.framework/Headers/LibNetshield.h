#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

__attribute__((visibility("default")))
@interface LibNetshield : NSObject

/**
 * 启动防护服务，是否启动成功请在completionHandler中获取
 * @param pid               客服提供的pid
 * @param key               客服提供的key
 * @param completionHandler SDK初始化后的回调函数，在该函数中判断SDK是否启动成功
 *                          startResult SDK是否成功启动 YES-启动成功 NO-启动失败
 *                          errMessage  启动失败时用于获取失败原因，启动成功时可忽略
 *                          clientIP    启动成功时为客户端真实IP，启动失败为空
 */
+ (void)startService:(NSString *)pid key:(NSString *)key completionHandler:(void (^)(BOOL startResult, NSString *errMessage, NSString *clientIP))completionHandler;

/**
 * 停止防护服务，释放资源
 */
+ (void)stopService;

/**
 * 根据规则名获取监听端口，最好在startService的completionHandler中进行调用
 * @param rule 规则名
 * @return 本地监听端口
 */
+ (int)getLocalhostPort:(NSString *)rule;

@end

NS_ASSUME_NONNULL_END
