import styles from "@/components/Layout/styles";
import { useThemeContext } from "@/contexts/ThemeContext/useThemeContext";
import { useAppNavigation } from "@/hooks/useAppNavigation";
import { Image, Pressable, View } from "react-native";

function HeaderButton({ icon, iconStyle, onPress }) {
  return (
    <Pressable onPress={onPress} style={styles.navigationButton}>
      <Image
        style={[styles.navigationIcon, iconStyle]}
        resizeMode="contain"
        source={icon}
      />
    </Pressable>
  );
}

function Header({
  showLogo = true,
  backTo,
  accessoryLeft,
  accessoryRight,
  onClose,
  containerStyle,
  headerContentContainerStyle,
}) {
  const { currentScheme } = useThemeContext();
  const { goBack } = useAppNavigation();

  return (
    <View style={[styles.headerContainer, containerStyle]}>
      <View
        style={[styles.headerContentContainer, headerContentContainerStyle]}
      >
        {(accessoryLeft || backTo !== undefined || showLogo) && (
          <View style={styles.accessoryLeft}>
            {backTo !== undefined && (
              <HeaderButton
                icon={
                  currentScheme === "light"
                    ? require("@/assets/images/back_blue.png")
                    : require("@/assets/images/back.png")
                }
                onPress={backTo === null ? goBack : getGoTo(backTo)}
              />
            )}
            {showLogo && (
              <Image
                style={styles.logo}
                resizeMode="contain"
                source={require("@/assets/icon.png")}
              />
            )}
            {accessoryLeft}
          </View>
        )}
        {(accessoryRight || onClose) && (
          <View style={styles.accessoryRight}>
            {accessoryRight}
            {onClose !== undefined && (
              <HeaderButton
                icon={require("@/assets/images/x.png")}
                onPress={onClose}
              />
            )}
          </View>
        )}
      </View>
    </View>
  );
}

Header.Button = HeaderButton;

export { Header };
