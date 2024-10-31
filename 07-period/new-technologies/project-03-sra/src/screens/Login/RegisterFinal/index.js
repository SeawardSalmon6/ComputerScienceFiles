import { Button } from "@/components/Button";
import { Form } from "@/components/Form";
import { Input } from "@/components/Input";
import { useAppNavigation } from "@/hooks/useAppNavigation";
import { LoginLayout } from "@/screens/Login/components/LoginLayout";
import styles from "@/screens/Login/styles";
import { isAllFieldsFilled } from "@/utils/isAllFieldsFilled";
import { useRoute } from "@react-navigation/native";
import { useEffect, useState } from "react";
import { Controller, useForm } from "react-hook-form";
import { Text } from "react-native";

const FORM_FIELDS = ["password", "confirmPassword"];

export function RegisterFinalScreen() {
  const { params } = useRoute();
  const { values } = params ?? {};

  const [isButtonDisabled, setIsButtonDisabled] = useState(true);
  const { getGoTo } = useAppNavigation();

  const { watch, control, setValue } = useForm();
  watch((values) => {
    setIsButtonDisabled(!isAllFieldsFilled(values ?? {}, FORM_FIELDS));
  });

  useEffect(() => {
    if (values) {
      Object.entries(values).forEach(([key, value]) => {
        setValue(key, value);
      });
    }
  }, []);

  return (
    <LoginLayout title="só pra finalizar," subtitle="crie uma senha segura">
      <Form>
        <Controller
          control={control}
          name="password"
          render={({ field: { value, onChange } }) => (
            <Input
              type="password"
              label="senha"
              value={value}
              onChange={onChange}
            />
          )}
        />
        <Controller
          control={control}
          name="confirmPassword"
          render={({ field: { value, onChange } }) => (
            <Input
              type="password"
              label="repita sua senha"
              value={value}
              onChange={onChange}
            />
          )}
        />
        <Text style={styles.tip}>
          escreva no mínimo 8 caracteres, 1 número e 1 letra maiúscula
        </Text>
        <Button
          onPress={getGoTo("ConfirmationSplash")}
          disabled={isButtonDisabled}
        >
          cadastrar
        </Button>
      </Form>
    </LoginLayout>
  );
}
