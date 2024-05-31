import { DismissKeyboard } from "@/components/DismissKeyboard";
import styles from "@/components/Layout/styles";
import { useThemeContext } from "@/contexts/ThemeContext/useThemeContext";
import { ScrollView, View } from "react-native";
import { SafeAreaView, useSafeAreaFrame } from "react-native-safe-area-context";

export function Layout({
  children,
  rootStyle,
  contentContainerStyle,
  addExtraSpace,
}) {
  const { height } = useSafeAreaFrame();
  const { colors } = useThemeContext();

  return (
    <DismissKeyboard>
      <View style={[{ backgroundColor: colors.background }, rootStyle]}>
        <SafeAreaView style={[styles.root]}>
          <ScrollView
            contentContainerStyle={[
              styles.contentContainer,
              addExtraSpace && { paddingBottom: height / 3 },
              contentContainerStyle,
            ]}
          >
            {children}
          </ScrollView>
        </SafeAreaView>
      </View>
    </DismissKeyboard>
  );
}
