import { View } from "react-native";
import { BackButton } from "../BackButton";
import { Divider, TopNavigation } from "@ui-kitten/components";
import { styles } from "./styles";

export function Header({
  title,
  accessoryLeft,
  accessoryRight,
  backTo,
  hideDivider,
  children,
  containerStyle,
  ...props
}) {
  return (
    <>
      <View style={{ ...styles.header, ...containerStyle }}>
        <TopNavigation
          title={title}
          alignment="center"
          accessoryLeft={
            <>
              {backTo !== undefined && <BackButton backTo={backTo} />}
              {accessoryLeft}
            </>
          }
          accessoryRight={accessoryRight}
          style={{
            paddingHorizontal: 0,
            paddingVertical: 0,
          }}
          {...props}
        />
        {children}
      </View>
      {!hideDivider && <Divider style={styles.divider} />}
    </>
  );
}
